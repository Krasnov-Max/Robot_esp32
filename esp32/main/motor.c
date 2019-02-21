#include "motor.h"
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

void LeftMotor(uint16_t DUTY, uint8_t Dir, double acs)
{
  uint8_t duty;
  duty= (DUTY*100/32767);
  duty = duty *acs;
  mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_0,MCPWM_OPR_B, duty);
  mcpwm_set_duty_type(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B, MCPWM_DUTY_MODE_0);
  switch (Dir)
    {
      case UpMotor:
        gpio_set_level(GPIO_DIR_LEFT_F, 1);
        gpio_set_level(GPIO_DIR_LEFT_R, 0);
        break;
      case DownMotor:
        gpio_set_level(GPIO_DIR_LEFT_F, 0);
        gpio_set_level(GPIO_DIR_LEFT_R, 1);
        break;
      case StopMotor:
        gpio_set_level(GPIO_DIR_LEFT_F, 0);
        gpio_set_level(GPIO_DIR_LEFT_R, 0);
        mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_0,MCPWM_OPR_B, 0);
        mcpwm_set_duty_type(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B, MCPWM_DUTY_MODE_0);
        break;
    }
}

void RightMotor(uint16_t DUTY, uint8_t Dir, double acs)
{
  uint8_t duty;
  duty= (DUTY*100/32767);
  duty = duty *acs;
  mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_0,MCPWM_OPR_A, duty);
  mcpwm_set_duty_type(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, MCPWM_DUTY_MODE_0);
  switch (Dir)
    {
      case UpMotor:
        gpio_set_level(GPIO_DIR_RIGHT_F, 1);
        gpio_set_level(GPIO_DIR_RIGHT_R, 0);
        break;
      case DownMotor:
        gpio_set_level(GPIO_DIR_RIGHT_F, 0);
        gpio_set_level(GPIO_DIR_RIGHT_R, 1);
        break;
      case StopMotor:
        gpio_set_level(GPIO_DIR_RIGHT_F, 0);
        gpio_set_level(GPIO_DIR_RIGHT_R, 0);
        mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_0,MCPWM_OPR_A, 0);
        mcpwm_set_duty_type(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, MCPWM_DUTY_MODE_0);
        break;
    }
}
void allMotorStop(void)
{
  mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_0,MCPWM_OPR_A, 0);
  mcpwm_set_duty_type(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, MCPWM_DUTY_MODE_0);
  mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_0,MCPWM_OPR_B, 0);
  mcpwm_set_duty_type(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B, MCPWM_DUTY_MODE_0);
  gpio_set_level(GPIO_DIR_LEFT_F, 0);
  gpio_set_level(GPIO_DIR_LEFT_R, 0);
  gpio_set_level(GPIO_DIR_RIGHT_F, 0);
  gpio_set_level(GPIO_DIR_RIGHT_R, 0);
}
