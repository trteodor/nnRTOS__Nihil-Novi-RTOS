#include "nnRTOS.h"



void nnOsSemaphoreInit(int32_t *semaphore,int32_t value){

	 *semaphore = value;
	
}


void nnOsSignalSet(int *semaphore)
{
	 ENTRY_CRITCAL();
	  *semaphore +=1;
	 LEAVE_CIRITAL();
}

void nnOsSignalWait(int32_t *semaphore)
{
	ENTRY_CRITCAL();
	
	while(*semaphore <=0)
	{
		ENTRY_CRITCAL();
		LEAVE_CIRITAL();
	}

	 *semaphore -=1;
	LEAVE_CIRITAL();
}

void nnOsSignalCooperativeWait(int32_t *semaphore)
{
	ENTRY_CRITCAL();
	
	while(*semaphore<=0){
		ENTRY_CRITCAL();
		nnOsThreadYield();
		LEAVE_CIRITAL();
	}
	ENTRY_CRITCAL();
	*semaphore -=1;
	 LEAVE_CIRITAL();
}