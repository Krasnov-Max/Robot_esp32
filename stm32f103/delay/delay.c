#include <stm32f10x.h>
#include "delay.h"

static volatile  uint32_t TimingDelay;
NVIC_InitTypeDef  NVIC_InitStructure;

void Delay_ms( uint32_t nTime)
{ 
  
	NVIC_InitStructure.NVIC_IRQChannel = SysTick_IRQn ;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 5;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);		
 
 SysTick->LOAD=TimerTick_1ms;		
 SysTick->VAL=TimerTick_1ms;		
 
 SysTick->CTRL=	SysTick_CTRL_CLKSOURCE_Msk |
                SysTick_CTRL_TICKINT_Msk   |
                SysTick_CTRL_ENABLE_Msk;
	
  TimingDelay = nTime;
  while(TimingDelay != 0);
	SysTick->CTRL= ~ SysTick_CTRL_ENABLE_Msk;
}

void Delay_us(__IO uint32_t nTime)
{ 
		
 NVIC_InitStructure.NVIC_IRQChannel = SysTick_IRQn ;
 NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 5;
 NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
 NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
 NVIC_Init(&NVIC_InitStructure);		
 SysTick->LOAD=TimerTick_1us;		
 SysTick->VAL=TimerTick_1us;		
 
 SysTick->CTRL=	SysTick_CTRL_CLKSOURCE_Msk |
                SysTick_CTRL_TICKINT_Msk   |
                SysTick_CTRL_ENABLE_Msk;
	
  TimingDelay = nTime;
  while(TimingDelay != 0);
	SysTick->CTRL= ~ SysTick_CTRL_ENABLE_Msk;
}

void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}


void SysTick_Handler(void)
{
  TimingDelay_Decrement();
	
}
