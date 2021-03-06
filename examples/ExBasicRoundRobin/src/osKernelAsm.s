.section .text
.cpu cortex-m4
.syntax unified
.global currentPt
.global SysTick_Handler
.global nnOsSchedulerLaunch
.thumb
.type SysTick_Handler, function
.word SysTick_Handler

.type nnOsSchedulerLaunch, function
.word nnOsSchedulerLaunch

@ //Dobra wiec on to poprostu te r0,r1,r2 automatycznie zrzuci
@ //A gdy wraca to zna wierzcholek stosu - wiec znowu zrzuci automatycznie bo wrocil
@ //Ale ze ma inny adres wierzcholka stosu no to zdejmie z innego stosu te rejestry automatycznie
@ //Wiec caly kontekst przywracany jest automatycznie Wow gites easy peasy!
SysTick_Handler:          @save r0,r1,r2,r3,r12,lr,pc,psr      
                CPSID   I                  
                PUSH    {R4-R11}        @save r4,r5,r6,r7,r8,r9,r10,r11   
                LDR     R0, =currentPt  @ r0 points to currentPt       
                LDR     R1, [R0]        @ r1= currentPt   
                STR     SP, [R1]           
                LDR     R1, [R1,#4]     @ r1 =currentPt->next   
                STR     R1, [R0]        @currentPt =r1   
                LDR     SP, [R1]        @SP= currentPt->stackPt   
                POP     {R4-R11}           
                CPSIE   I                  
                BX      LR 
	
	
	

nnOsSchedulerLaunch:
            LDR     R0, =currentPt         
            LDR     R2, [R0]       @ R2 =currentPt       
            LDR     SP, [R2]       @SP = currentPt->stackPt    
            POP     {R4-R11}          
            POP     {R0-R3}            
            POP     {R12}
            ADD     SP,SP,#4           
            POP     {LR}               
            ADD     SP,SP,#4         
            CPSIE   I                 
            BX      LR                 

.align
.end