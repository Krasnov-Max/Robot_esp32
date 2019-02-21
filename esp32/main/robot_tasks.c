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


void parrsing(void *pvParameters)
{
  my_tcp_packet pack;
  bool result;
  uint8_t life = 0;
  while (1)
    {
      result = xQueueReceive(Motor_Queue_Recive, &pack, portMAX_DELAY);
      life = 0;
      if (pack.start_1=='+' && pack.start_2=='+')
        {
          switch (pack.distanation)
            {
                case DestanationToLife:
                  {
                    if (pack.Left_Right == 255 && pack.Up_Down == 255 && pack.Value == 125)
                      {
                        life = 1;
                         xQueueSend(LIFE_Queue, &life, 100);
                        life = 0;
                       }
                    break;
                  }
                case DestanationToMotor:
                  {
                    life = 1;
                    xQueueSend(LIFE_Queue, &life, 100);
                    life = 0;
                    switch (pack.Left_Right)
                      {
                        case LeftMotorData:
                          {
                            LeftMotor(pack.Value, pack.Up_Down, pack.acs);
                            break;

                          }
                        case RightMotorData:
                          {
                            RightMotor(pack.Value, pack.Up_Down, pack.acs);
                            break;
                          }
                      }
                    break;
                  }
                case DestanationToUSART:
                  {
                    life = 1;
                    xQueueSend(LIFE_Queue, &life, 100);
                    life = 0;
                    break;
                  }
            }
        }
    }
}

void life_client(void *pvParameters)
{
  uint8_t pack;
  bool i;
  int j=0;
  vTaskDelay(1000);
  while(1)
    {
      i = xQueueReceive(LIFE_Queue,&pack, 6000);
      if (!i)
        {
          break;
        } else
            {
              if (!pack)
                {
                  break;
                }
              j++;
            }
    }
  ServEv=0;
  vTaskDelete(NULL);
}

void ServerTask(void *pvParameters)
{
  int i;
  ServEv=0;

  socket_id = socket(PF_INET, SOCK_STREAM, 0);
  if ( socket_id > 0 )
    {
      memset(&addr, 0, sizeof(struct sockaddr_in));
      addr.sin_family = AF_INET;
      addr.sin_addr.s_addr = 0;
      addr.sin_port = htons(8787);
      if (bind(socket_id, (struct sockaddr *)&addr, sizeof(addr)) != -1)
        {
             listen(socket_id,3);
              while(1)
                {
                  accept_id = accept(socket_id, (struct sockaddr*)&addr,&addr_len);
                  if(accept_id > 0)
                    {
                      ServEv = 1;
                      xTaskCreate(life_client, "Life", 2048, NULL, tskIDLE_PRIORITY + 2, NULL);
                      while(!ServEv){}
                    }
                }
        } else
            {
            }
    }
}
void ServerReadTask(void* pvParameters)
{
  int bytes_available;
  my_tcp_packet pack;
  while (1)
    {
      while (ServEv)
        {
          lwip_ioctl(accept_id,FIONREAD,&bytes_available);
          if (bytes_available >0)
            {
             while(1)
               {
                 if (bytes_available < sizeof(my_tcp_packet)) {break;}
                 if (ServEv) {read(accept_id,&pack, sizeof (my_tcp_packet));}
                  lwip_ioctl(accept_id,FIONREAD,&bytes_available);
                 if (ServEv) {xQueueSend(Motor_Queue_Recive, &pack,4);}
               }
            }
        }
        close(accept_id);
    }
}

void server (void *pvParameters)
{
   while(1)
      {
        xEventGroupWaitBits(wifi_event_group, CLIENT_CONNECTED_BIT,false, true, portMAX_DELAY);
        xTaskCreate(ServerTask, "servertask", 2048, NULL, tskIDLE_PRIORITY + 1, &server_handle);
        ESP_LOGI(TAG, "Connected to AP\r\n");

        xEventGroupWaitBits(wifi_event_group, CLIENT_DISCONNECTED_BIT,false, true, portMAX_DELAY);
        ESP_LOGI(TAG, "DisConnected to AP\r\n");
        ServEv=0;
        close(accept_id);
        close(socket_id);
        socket_id = -1;
        accept_id = -1;
        vTaskDelete(server_handle);

      }
}
void led_blink ( void *arg )
{
    int level = 0;
    while (1)
      {
          gpio_set_level(LED, (uint32_t)level);
          level = !level;
          vTaskDelay(600 / portTICK_PERIOD_MS);
      }
}
