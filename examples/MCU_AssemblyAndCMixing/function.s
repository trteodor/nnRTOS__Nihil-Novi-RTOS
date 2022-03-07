.section .text
.cpu cortex-m4
.global asmFun


asmFun:
    mov r0,#0x64
    BX LR

.align
.end
