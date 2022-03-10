#ifndef __NN_TASK_H__
#define __NN_TASK_H__

#include "stdint.h"

uint8_t nn_AddThread(void(*taskFunName)(void),uint32_t priority);

#endif 