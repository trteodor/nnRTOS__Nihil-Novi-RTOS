
#include "nnRTOS.h"
#include "stm32f4xx.h"                  // Device header
#include "stdint.h"

#include "BSP_GPIO.h"

uint32_t count6,count7;

void Task6(void)
{
	 while(1){
		volatile uint32_t receivedValue =  nnOsFifoGet();
		(void)receivedValue;
		count6++;
		tooglePIN(GPIOD, Psm13);
		tooglePIN(GPIOD, Psm14);
		tooglePIN(GPIOD, Psm15);
		nnOsThreadSleep(200);
	 }
}

void Task7(void)
{
	 while(1){
		volatile static uint32_t ValueToTransmit;
		ValueToTransmit++;
		nnOsFifoPut(ValueToTransmit);
		count7++;
		tooglePIN(GPIOD, Psm12);
		nnOsThreadSleep(100);
	 }
}

int main(void)
{

	BSP_LedGPIO_Init();

	nnOsKernelInit();
	if(nnOsAddThread(&Task7,1) != Call_ok)
	{
		while(1); //Error!
	}
	if(nnOsAddThread(&Task6,1) != Call_ok)
	{
		while(1); //Error!
	}

	nnOsFifoInit(); //TODO: write useable functions for queues ... e.g. forwarding the address of a queue and many more this implementation is very lazy ..
	nnOsKernelLaunch(QUANTA);
}

