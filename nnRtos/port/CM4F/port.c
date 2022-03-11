#include "stm32f407xx.h"
/*Here Include Your Device header (from CMSIS Library) */

uint32_t nnOs_SystemTime;

//Cortex Registers defines..
#define SYSPRI3         (*((volatile uint32_t *)0xE000ED20))
#define INTCTRL         (*((volatile uint32_t *)0xE000ED04))

void nnOsSchedulerLaunch(void);

void nnOsPort_KernelLaunch(uint32_t quanta, uint32_t millis_prescaler){
	SysTick->CTRL =0;
	SysTick->VAL  =0;
	SysTick->LOAD =  (quanta*millis_prescaler)-1;

	SYSPRI3 =(SYSPRI3&0x00FFFFFF)|0xE0000000; // priority 7
	SysTick->CTRL =  0x00000007;

	nnOsSchedulerLaunch();
}

void nnPort_ThreadYield(void){
 SysTick->VAL =0;
 INTCTRL = 0x04000000; // trigger SysTick
}

void  SysTick_Handler(void){
	nnOs_SystemTime++; //I'am lazy - solution using global var is ok :) 
  //Trigger PendSV
	INTCTRL  =  0x10000000;
}