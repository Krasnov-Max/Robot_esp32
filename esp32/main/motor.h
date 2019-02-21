#ifndef MOTOR_H
#define MOTOR_H

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
#include "hw_defs.h"


void RightMotor(uint16_t DUTY, uint8_t Dir, double acs);
void LeftMotor(uint16_t DUTY, uint8_t Dir, double acs);
void allMotorStop(void);
#endif // MOTOR_H
