
#include "nnRTOS.h"
#include "stm32f4xx.h"                  // Device header
#include "stdint.h"

uint32_t count6,count7;

void Task6(void)
{
	 while(1){
		volatile uint32_t receivedValue =  nnOsMailboxRecv();
		(void)receivedValue;
		count6++;
	 }
}

void Task7(void)
{
	 while(1){
		volatile static uint32_t ValueToTransmit;
		ValueToTransmit++;
		nnOsMailboxSend(ValueToTransmit);
		count7++;
		nnOsThreadSleep(100);
	 }
}

int main(void)
{
	nnOsKernelInit();
	if(nnOsAddThread(&Task7,1) != Call_ok)
	{
		while(1); //Error!
	}
	if(nnOsAddThread(&Task6,1) != Call_ok)
	{
		while(1); //Error!
	}

	nnOsMailboxInit(); //TODO: write useable functions for mailboxes ... e.g. forwarding the address of a queue and many more this implementation is very lazy ..
	nnOsKernelLaunch(QUANTA);
}

