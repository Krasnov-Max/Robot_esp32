#include "stm32f10x.h"
#define F_CPU 		72000000UL
#define TimerTick_1ms  	F_CPU/1000-1 
#define TimerTick_1us  	F_CPU/1000000-1 


void Delay_ms(uint32_t nTime);
void Delay_us(uint32_t nTime);

