#Example sources:
SRC +=  examples/ExQueue/src/main.c


#nnRTOS sources
SRC += nnRtos/src/nnKernel.c
SRC += nnRtos/port/CM4F/port.c
SRC += nnRtos/src/semaphores.c
SRC += nnRtos/src/queues.c
#nnRTOS asm file
ASM += nnRtos/port/CM4F/portAsm.s

#BSP
SRC += Drivers/GPIO_Driver/src/BSP_GPIO.c

#Device Startup
ASM += common/startup_stm32f407xx.s

INC_DIR += -IDrivers/GPIO_Driver/inc
INC_DIR += -InnRtos
INC_DIR += -InnRtos/inc
INC_DIR += -InnRtos/port/CM4F
INC_DIR += -Icommon/Inc
INC_DIR += -IDrivers/CMSIS/Device/ST/STM32F4xx/Include
INC_DIR += -IDrivers/CMSIS/Include
INC_DIR += -IDrivers/CMSIS/Core/Include
INC_DIR += -Iexamples/PrioritySchedule/inc

# link script
LDSCRIPT = STM32F407VGTx_FLASH.ld