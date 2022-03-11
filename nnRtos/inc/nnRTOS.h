#ifndef __NN_TASK_H__
#define __NN_TASK_H__

#include "stdint.h"
#include "nn_rtosTypes.h"
#include "config.h"
#include "port_macros.h"

void nnOsKernelInit(void);
void nnOsKernelLaunch(uint32_t quanta);
void nnOsThreadYield(void);

nn_CallRes_t nnOsAddThread(void(*taskFunName)(void),uint32_t priority);

void osThreadSleep(uint32_t sleep_time);

uint32_t nnOs_GetSystemTime(void);

#endif 