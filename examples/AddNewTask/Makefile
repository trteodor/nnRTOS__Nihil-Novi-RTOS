
SRC +=  examples/AddNewTask/src/main.c

SRC += nnRtos/src/nnKernel.c
SRC += nnRtos/port/CM4F/port.c
ASM += nnRtos/port/CM4F/portAsm.s


ASM += common/startup_stm32f407xx.s

INC_DIR += -InnRtos/inc
INC_DIR += -InnRtos/port/CM4F
INC_DIR += -Icommon/Inc
INC_DIR += -IDrivers/CMSIS/Device/ST/STM32F4xx/Include
INC_DIR += -IDrivers/CMSIS/Include
INC_DIR += -IDrivers/CMSIS/Core/Include
INC_DIR += -Iexamples/PrioritySchedule/inc

# link script
LDSCRIPT = STM32F407VGTx_FLASH.ld