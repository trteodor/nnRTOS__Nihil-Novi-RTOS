# Simple Nihil Novi RTOS! :) 

This project was created only for educational purposes.

Directory "examples" contain few examples.

* In Directory "nnRtos" you will see sources for nnRtos and Port for Cortex-M4 (tested with stm32f407) 

    * IMPORTANT!!! check file "port.c" to verify your (included from CMSIS library) Device Header (eventually compilation process will return fail)

**_In Directory "examples" i added  example "BasicRoundRobic". This example use him own sources to show maximally minimum implementation RTOS in CM4. This example also implement basic RoundRobin scheduler._**


ScreenShot from debugging nnRTOS:


![nnFifoDebugSS](https://github.com/trteodor/nnRTOS__Nihil-Novi-RTOS/blob/master/pictures/nnFifoDebugSe.png)

Board Used to tests - well known Discovery STM32F407:

![Board](https://github.com/trteodor/nnRTOS__Nihil-Novi-RTOS/blob/master/pictures/usedBoard.png)

* You are ready to start adventure with this RTOS when you have this tools in your environment (environment variables)!

    * arm-none-eabi-gcc 9.3.1

    * OpenOCD 0.11.0

    * make 4.2.1

        
Finally:

 **_Call "make" in this project at him location to show this information:_**

    How Use this build system:
    1. Call: make App                          -To compile Default App - Firmware for MCU (without debug information)
    2. Call: make debugC                       -To remove build folder, compile Default App with Debug information and flash Firmware in MCU
    3. Call: make debug                        -To compile Default App with Debug information and flash Firmware in MCU
    4. Call: make flash                        -To compile and flash Default App - Firmware for MCU (without debug information)
    5. Call: make CompileAllApps               -To compile All Apps - Firmwares for MCU
    6. Call: make CompileAllAppsDebug          -To compile All Apps with Debug information - Firmwares for MCU
    7. Call: make CompileApp App=AppName       -To compile Choosen App - Firmware for MCU (AppName its Parameter) (without debug information)
    8. Call: make CompileAppflash App=AppName  -To compile Choosen App and flash firmware in MCU (AppName its Parameter) (without debug information)
    9. Call: make CompileAppDebug App=AppName  -To compile Choosen App with Debug information and flash Firmware in MCU (AppName its Parameter)
    ------------------------------------
    10. Call: make test-ra       -To start compilation or fully recompilation all unit-test
    11. Call: make test-s        -Only to rebuild source files and start unit tests
    12. Call: make coverage      -To refresh coverage report
    ------------------------------------
    13. Call: make clean-test    -To delete all test result
    14. Call: make clean-docs    -Remove Docs Folder
    ------------------------------------
    15. Call: make cleanR         -Remove build Release Folder
    15. Call: make cleanD         -Remove build Debug Folder



This project use my own build system created using makefiles if you want you can adapt him to your projects

Examples for MailBox and Queue are very lazy... To use it you have to develop this functionality. Just check sources to know the problem. Neverless examples work correct 

I Also prepare template for unit tests - but i didn't write any test. Im'too lazy... as you know writing tests taking a bit time..

**_If you have question please open issue to this repository._**