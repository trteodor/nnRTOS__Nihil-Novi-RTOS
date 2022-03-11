#ifndef __NN_PORT_MACROS_H__
#define __NN_PORT_MACROS_H__

#define ENTRY_CRITCAL() __disable_irq() 
#define LEAVE_CIRITAL() __enable_irq()

#endif