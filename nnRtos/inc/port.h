#ifndef __NN_PORT_H__
#define __NN_PORT_H__

#include <stdint.h>

void osKernelLaunch(uint32_t quanta);
void osKernelInit(void);


uint8_t osKernelAddThreads( void(*task0)(void),uint32_t p0,
														void(*task1)(void),uint32_t p1,
														void(*task2)(void),uint32_t p2,
														void(*task3)(void),uint32_t p3,
														void(*task4)(void),uint32_t p4,
														void(*task5)(void),uint32_t p5,
														void(*task6)(void),uint32_t p6,
														void(*task7)(void),uint32_t p7);
void osThreadYield(void);


uint8_t osKernelAddPeriod_Thread(void (*task)(void), uint32_t period);


void periodicTask1(void);

void periodicTask2(void);

void osSemaphoreInit(int32_t *semaphore,int32_t value);
void osSignalSet(int *semaphore);
void osSignalWait(int32_t *semaphore);
void osSignalCooperativeWait(int32_t *semaphore);

void osThreadSleep(uint32_t sleep_time);


void osMailboxInit(void);
void osMailboxSend(uint32_t data);
uint32_t osMailboxRecv(void);


void osFifoInit(void);
int8_t osFifoPut(uint32_t data);
uint32_t osFifoGet(void);


void osEdgeTriggerInit(int32_t *semaphore);

#endif