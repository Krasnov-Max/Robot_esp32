#ifndef ROBOT_TASKS_H
#define ROBOT_TASKS_H

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
#include "hw_defs.h"


extern QueueHandle_t LIFE_Queue;
extern QueueHandle_t Motor_Queue_Recive;
extern QueueHandle_t Motor_Queue_Send;
extern QueueHandle_t USART_Queue_Recive;
extern QueueHandle_t USART_Queue_Send;
extern  unsigned int ServEv;
extern  const char *TAG ;
extern EventGroupHandle_t wifi_event_group;
extern EventGroupHandle_t server_event;
extern  const int SERVER_CLIENT_CONNECTED_BIT;
extern  const int SERVER_CLIENT_DISCONNECTED_BIT;
extern  const int CLIENT_CONNECTED_BIT;
extern  const int CLIENT_DISCONNECTED_BIT;
extern xTaskHandle server_handle;
extern struct sockaddr_in addr, client_addr;
extern int socket_id, accept_id;
extern socklen_t addr_len;

void ServerReadTask(void* pvParameters);
void parrsing(void *pvParameters);
void life_client(void *pvParameters);
void server (void *pvParameters);
void ServerTask(void *pvParameters);
void led_blink ( void *arg );
#endif // ROBOT_TASKS_H
