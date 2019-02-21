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

void GPIO_Init (void)
{
    gpio_config_t gp;
    gp.intr_type = GPIO_INTR_DISABLE;
    gp.mode = GPIO_MODE_OUTPUT;
    gp.pull_down_en = GPIO_PULLDOWN_ENABLE;
    gp.pull_up_en = GPIO_PULLUP_DISABLE;
    gp.pin_bit_mask = GPIO_SEL_18 | GPIO_SEL_19 | GPIO_SEL_21 | GPIO_SEL_22 | GPIO_SEL_2;
    gpio_config(&gp);
    gpio_set_direction((gpio_num_t)LED, GPIO_MODE_OUTPUT);
    gpio_set_direction((gpio_num_t)GPIO_DIR_LEFT_F, GPIO_MODE_OUTPUT);
    gpio_set_direction((gpio_num_t)GPIO_DIR_LEFT_R, GPIO_MODE_OUTPUT);
    gpio_set_direction((gpio_num_t)GPIO_DIR_RIGHT_F, GPIO_MODE_OUTPUT);
    gpio_set_direction((gpio_num_t)GPIO_DIR_RIGHT_R, GPIO_MODE_OUTPUT);
    gpio_set_level((gpio_num_t)GPIO_DIR_LEFT_F, 0);
    gpio_set_level((gpio_num_t)GPIO_DIR_LEFT_R, 0);
    gpio_set_level((gpio_num_t)GPIO_DIR_RIGHT_F, 0);
    gpio_set_level((gpio_num_t)GPIO_DIR_RIGHT_R, 0);
}

void PWM_Init (void)
{
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, GPIO_PWM_A);
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0B, GPIO_PWM_B);
    mcpwm_config_t pwm_config;
    pwm_config.frequency = 25000;    //frequency = 30 KHz,
    pwm_config.cmpr_a = 0;    //duty cycle of PWMxA = 0
    pwm_config.cmpr_b = 0;    //duty cycle of PWMxb = 0
    pwm_config.counter_mode = MCPWM_UP_COUNTER;
    pwm_config.duty_mode = MCPWM_DUTY_MODE_0;
    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwm_config);
    mcpwm_set_signal_low(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A);
    mcpwm_set_signal_low(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B);
    mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_0,MCPWM_OPR_A, 0);
    mcpwm_set_duty_type(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, MCPWM_DUTY_MODE_0);
    mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_0,MCPWM_OPR_B, 0);
    mcpwm_set_duty_type(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B, MCPWM_DUTY_MODE_0);
}

void uart_init() {
    const uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };
    uart_param_config(UART_NUM_1, &uart_config);
    uart_set_pin(UART_NUM_0, TX, RX, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    // We won't use a buffer for sending data.
    uart_driver_install(UART_NUM_0, 1024 * 2, 0, 0, NULL, 0);
}
