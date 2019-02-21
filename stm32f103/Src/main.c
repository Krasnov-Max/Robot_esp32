#define F_CPU 8000000UL
#include <stdio.h>
#include <stdlib.h>
#include "stm32f10x.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"

//#include "delay.h"



#define USE_STDPERIPH_DRIVER
#define testbit(data,bitno) ((data>>bitno)&0x01)

GPIO_InitTypeDef PORT_LED ;
TIM_TimeBaseInitTypeDef TIM1_Base;
TIM_OCInitTypeDef TIM1_PWM;
void TIM_INIT( void )
{
    TIM1_Base.TIM_Prescaler=1440-1;
    TIM1_Base.TIM_Period=1000;
    TIM1_Base.TIM_CounterMode=TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM1, &TIM1_Base);
    TIM_Cmd(TIM1,ENABLE);
    TIM1_PWM.TIM_OCMode=TIM_OCMode_PWM1;
    TIM1_PWM.TIM_OutputState=TIM_OutputState_Enable;
 //   TIM1_PWM.TIM_Pulse = 20;
    TIM_OC1Init(TIM1, &TIM1_PWM);
    TIM_OC2Init(TIM1, &TIM1_PWM);

 //   TIM_CCxCmd(TIM1, TIM_Channel_1, TIM_CCx_Enable);
 //   TIM_CCxCmd(TIM1, TIM_Channel_2, TIM_CCx_Enable);
    TIM_CtrlPWMOutputs(TIM1,ENABLE);
    TIM1->CCR1=80; // Left Right 30-140
    TIM1->CCR2=105;//UP Down 30-140
}
void blinkTask(void *pvParameters)
{
    while(1)
    {

        GPIO_SetBits(GPIOE,GPIO_Pin_0);
        GPIO_ResetBits(GPIOE,GPIO_Pin_2);
        vTaskDelay(200);
        GPIO_ResetBits(GPIOE,GPIO_Pin_0);
        GPIO_SetBits(GPIOE,GPIO_Pin_2);
        vTaskDelay(200);
    }
}

 void main (void)
 {
     SystemInit();

  // InitRCC();
   //GPIO_InitTypeDef PORT_LED ;
    uint32_t i;
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE ,ENABLE);
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

   PORT_LED.GPIO_Mode = GPIO_Mode_Out_PP;
   PORT_LED.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_2;
   PORT_LED.GPIO_Speed = GPIO_Speed_50MHz;

   GPIO_Init(GPIOE, &PORT_LED);
   PORT_LED.GPIO_Mode = GPIO_Mode_AF_PP;
   PORT_LED.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
   PORT_LED.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_Init(GPIOA, &PORT_LED);


    TIM_INIT();
    xTaskCreate(blinkTask,"Blinker", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
    vTaskStartScheduler();


 }	 
