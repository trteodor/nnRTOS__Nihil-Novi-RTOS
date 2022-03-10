
SRC +=  examples/PrioritySchedule/src/main.c

SRC += nnRtos/port/CM4F/port.c
ASM += nnRtos/port/CM4F/portAsm.s


ASM += common/startup_stm32f407xx.s

INC_DIR += -InnRtos/inc/CM4F/
INC_DIR += -Icommon/Inc
INC_DIR += -IDrivers/CMSIS/Device/ST/STM32F4xx/Include
INC_DIR += -IDrivers/CMSIS/Include
INC_DIR += -IDrivers/CMSIS/Core/Include
INC_DIR += -Iexamples/PrioritySchedule/inc

# link script
LDSCRIPT = STM32F407VGTx_FLASH.ld