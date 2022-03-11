#ifndef __NN_PORTHEADER_H__
#define __NN_PORTHEADER_H__


void nnOs_RegisterIncSysTimeFuntion(void(*IncSysTimeFun)(void));
void nnOsPort_KernelLaunch(uint32_t quanta, uint32_t millis_prescaler);
void nnPort_ThreadYield(void);


//Export Global 
uint32_t nnOs_SystemTime;

#endif