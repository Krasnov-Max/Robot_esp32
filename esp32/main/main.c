#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/event_groups.h"
#include "esp_attr.h"
#include "soc/rtc.h"
#include "driver/mcpwm.h"
#include "soc/mcpwm_reg.h"
#include "soc/mcpwm_struct.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "esp_spi_flash.h"
#include "esp_log.h"
#include "string.h"
#include "lwip/err.h"
#include "lwip/sockets.h"
#include <sys/ioctl.h>
#include "lwip/sys.h"
#include "lwip/netdb.h"
#include "lwip/dns.h"
#include "driver/uart.h"
#include "soc/uart_struct.h"
#include "packet_typedef.h"
#include "motor.h"
#include "robot_tasks.h"
#include "hw_defs.h"
#include "hw_init.h"





#define AP_SSID "Robot"
#define STA_SSID "max_naladka"
#define STA_PASS "descensus"
#define AP_PASSPHARSE "memorex1"
#define AP_SSID_HIDDEN 0
#define AP_MAX_CONNECTIONS 1
#define AP_AUTHMODE WIFI_AUTH_WPA2_PSK // the passpharese should be atleast 8 chars long
#define AP_BEACON_INTERVAL 100 // in milli seconds
const char *TAG = "Server:";
EventGroupHandle_t wifi_event_group;
EventGroupHandle_t server_event;
unsigned int ServEv=0;
const int SERVER_CLIENT_CONNECTED_BIT = BIT0;
const int SERVER_CLIENT_DISCONNECTED_BIT = BIT1;

const int CLIENT_CONNECTED_BIT = BIT0;
const int CLIENT_DISCONNECTED_BIT = BIT1;

struct sockaddr_in addr, client_addr;
int socket_id, accept_id;
socklen_t addr_len;

//int socket_serv_desc, socket_serv_desc;
QueueHandle_t Motor_Queue_Recive;
QueueHandle_t Motor_Queue_Send;
QueueHandle_t USART_Queue_Recive;
QueueHandle_t USART_Queue_Send;
QueueHandle_t LIFE_Queue;
xTaskHandle server_handle;



esp_err_t event_handler(void *ctx, system_event_t *event)
{
  switch(event->event_id)
        {
            case SYSTEM_EVENT_AP_STACONNECTED:
                    xEventGroupSetBits(wifi_event_group, CLIENT_CONNECTED_BIT);
                    xEventGroupClearBits(wifi_event_group, CLIENT_DISCONNECTED_BIT);
                    break;
            case SYSTEM_EVENT_AP_STADISCONNECTED:
                    xEventGroupSetBits(wifi_event_group, CLIENT_DISCONNECTED_BIT);
                    xEventGroupClearBits(wifi_event_group, CLIENT_CONNECTED_BIT);
                    //  close(socket_id);
                    //  close(accept_id);
                    ServEv=0;
                    break;
            case SYSTEM_EVENT_STA_START:
                    esp_wifi_connect();
                    break;
            case SYSTEM_EVENT_STA_GOT_IP:
                    ESP_LOGI(TAG, "got ip:%s", ip4addr_ntoa(&event->event_info.got_ip.ip_info.ip));
                //    xEventGroupSetBits(wifi_event_group, WIFI_CONNECTED_BIT);
                    xEventGroupSetBits(wifi_event_group, CLIENT_CONNECTED_BIT);
                    xEventGroupClearBits(wifi_event_group, CLIENT_DISCONNECTED_BIT);
                    break;
            default:
                    break;
        }
      return ESP_OK;
}




static void start_dhcp_server()
{
    tcpip_adapter_init();
    // stop DHCP server
    ESP_ERROR_CHECK(tcpip_adapter_dhcps_stop(TCPIP_ADAPTER_IF_AP));
    // assign a static IP to the network interface
    tcpip_adapter_ip_info_t info;
    memset(&info,0, sizeof(info));
    IP4_ADDR(&info.ip, 192, 168, 1, 1);
    IP4_ADDR(&info.gw, 192, 168, 1, 1);//ESP acts as router, so gw addr will be its own addr
    IP4_ADDR(&info.netmask, 255, 255, 255, 0);
    ESP_ERROR_CHECK(tcpip_adapter_set_ip_info(TCPIP_ADAPTER_IF_AP, &info));
    // start the DHCP server
    ESP_ERROR_CHECK(tcpip_adapter_dhcps_start(TCPIP_ADAPTER_IF_AP));

}
static void initialise_wifi_in_sta(void)
{
    esp_log_level_set("wifi", ESP_LOG_NONE); // disable wifi driver logging
    esp_log_level_set("nvs", ESP_LOG_NONE);
    tcpip_adapter_init();
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK( esp_wifi_init(&cfg) );
    ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));
    ESP_ERROR_CHECK( esp_wifi_set_mode(WIFI_MODE_STA) );
    // configure the wifi connection and start the interface
    wifi_config_t ap_config = {
        //.ap = {
        //        .ssid = STA_SSID,
        //        .password = STA_PASS,
        //        .ssid_len = 9,
        //        .channel = 0,
        //        .authmode = AP_AUTHMODE,
        //        .ssid_hidden = AP_SSID_HIDDEN,
        //        .max_connection = AP_MAX_CONNECTIONS,
        //        .beacon_interval = AP_BEACON_INTERVAL,
        //      },
        .sta = {
                    .ssid = STA_SSID,
                    .password = STA_PASS,
                },
};
    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &ap_config));
  //  ESP_ERROR_CHECK(esp_wifi_set_max_tx_power(78));
    ESP_ERROR_CHECK( esp_wifi_start() );

}






int app_main(void)
{
    nvs_flash_init();
   // printf("\n\r\n\rperiud %d", portTICK_PERIOD_MS);
    ESP_ERROR_CHECK( esp_event_loop_init(event_handler, NULL) );
    //lwip_init();
    lwip_socket_init();

    GPIO_Init();
    PWM_Init();
    uart_init();
    xTaskCreate(led_blink, "led blink", 2048, NULL, tskIDLE_PRIORITY + 1, NULL);
       wifi_event_group = xEventGroupCreate();
       server_event = xEventGroupCreate();
       Motor_Queue_Recive = xQueueCreate (10, sizeof(my_tcp_packet));
       Motor_Queue_Send = xQueueCreate (10, sizeof(my_tcp_packet));
       USART_Queue_Recive = xQueueCreate (10, sizeof(my_tcp_uart_packet));
       USART_Queue_Send = xQueueCreate (10, sizeof(my_tcp_uart_packet));
       LIFE_Queue = xQueueCreate (10, sizeof(uint8_t));
    //   start_dhcp_server();
       initialise_wifi_in_sta();
       xTaskCreate(ServerReadTask, "ServerReadTask", 4096, NULL, tskIDLE_PRIORITY + 2, NULL);
       xTaskCreate(parrsing, "Parssing", 2048, NULL, tskIDLE_PRIORITY + 2, NULL);
       xTaskCreate(server, "server", 2048, NULL, tskIDLE_PRIORITY + 2, NULL);
    while (1) {}

}

