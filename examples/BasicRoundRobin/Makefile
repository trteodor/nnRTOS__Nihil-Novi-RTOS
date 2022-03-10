
SRC +=  examples/BasicRoundRobin/src/main.c
SRC +=  examples/BasicRoundRobin/src/osKernel.c 

ASM += examples/BasicRoundRobin/src/osKernelAsm.s

ASM += common/startup_stm32f407xx.s

INC_DIR +=  -Icommon/Inc
INC_DIR += -IDrivers/CMSIS/Device/ST/STM32F4xx/Include
INC_DIR += -IDrivers/CMSIS/Include
INC_DIR += -Iexamples/BasicRoundRobin/inc

# link script
LDSCRIPT = STM32F407VGTx_FLASH.ld