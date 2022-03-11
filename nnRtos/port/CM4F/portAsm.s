.section .text
.cpu cortex-m4
.syntax unified
.thumb

.global currentPt
.global PendSV_Handler
.global nnOsSchedulerLaunch
.global nnOsPriorityScheduler
.type PendSV_Handler, function
.word PendSV_Handler

.type nnOsSchedulerLaunch, function
.word nnOsSchedulerLaunch

@ Dobra wiec on to poprostu te r0,r1,r2 automatycznie zrzuci
@ A gdy wraca to zna wierzcholek stosu - wiec je przywroci automatycznie bo wraca
@ Ale ze ma inny adres wierzcholka, po wyjsciu z tej funkcji no to zdejmie z innego stosu te rejestry
@ Wiec caly kontekst przywracany jest automatycznie
@ Proste
PendSV_Handler:          @save r0,r1,r2,r3,r12,lr,pc,psr      
                CPSID	  I
                PUSH 	  {R4-R11}
                LDR 	  R0,=currentPt
                LDR		  R1,[R0]
                
                STR 	  SP,[R1]

                PUSH	  {R0,LR}
                BL		  nnOsPriorityScheduler
                POP		  {R0,LR}
                LDR 	  R1,[R0]     @R1 = currentPt i.e New thread
                LDR 	  SP,[R1]
                
                POP		  {R4-R11}
                CPSIE	  I
                BX		  LR
	
	
	

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