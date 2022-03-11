
#include "nnRTOS.h"
#include "stm32f4xx.h"                  // Device header

#define	QUANTA	10


uint32_t count0,count1,count2, count3,count4,count5,count6,count7;




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
				 osThreadSleep(100);
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
		 
   		 count6++;

	 }
}

void Task7(void)
{
	 while(1){
		 count7++;


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
	nnOsKernelLaunch(QUANTA);
}

