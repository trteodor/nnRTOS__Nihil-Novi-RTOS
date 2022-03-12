
#include "nnRTOS.h"
#include "stm32f4xx.h"                  // Device header


uint32_t count0,count1,count2, count3,count4,count5,count6,count7;


int32_t semaphore1,semaphore2;

void Task0(void)
{
	 while(1){
   
		 count0++;
		 
	
	 }
}


void Task1(void)
{
	 while(1){
		 
   		 count1++;
		  if(count1 >  100)
				 nnOsThreadSleep(100);
	 }
}

void Task2(void)
{
	 while(1){

		 count2++;

	 }
}

void Task3(void)
{
	 while(1){
   		 count3++;

	
	 }
}


void Task4(void)
{
	 while(1){
		 
   		 count4++;

	 }
}

void Task5(void)
{
	 while(1){
		 count5++;


	 }
}

void Task6(void)
{
	 while(1){
		nnOsSignalSet((void *)&semaphore2);	
		nnOsSignalCooperativeWait((void *)&semaphore1);	
		count6++;
	 }
}

void Task7(void)
{
	 while(1){
		nnOsSignalCooperativeWait((void *)&semaphore2);		 
		nnOsSignalSet((void *)&semaphore1);		
		count7++;
		nnOsThreadSleep(100);
	 }
}

int main(void)
{
//Check in config.h MAX_NUM_OF_THREADS ...

	nnOsSemaphoreInit(&semaphore1,1);
	nnOsSemaphoreInit(&semaphore2,0);

	nnOsKernelInit();
	if(nnOsAddThread(&Task7,1) != Call_ok)
	{
		while(1); //Error!
	}
	if(nnOsAddThread(&Task6,1) != Call_ok)
	{
		while(1); //Error!
	}
	if(nnOsAddThread(&Task5,1) != Call_ok)
	{
		while(1); //Error!
	}
	if(nnOsAddThread(&Task4,1) != Call_ok)
	{
		while(1); //Error!
	}



	nnOsKernelLaunch(QUANTA);
}

