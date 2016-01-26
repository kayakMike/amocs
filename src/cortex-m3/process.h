#ifndef __PROCESS_H
#define __PROCESS_H
#include "micro_types.h"
#include "system.h"

#define EXEC_RETURN_HANDLER     0xFFFFFFF1  //return to ISR handler mode and use main stack pointer 
#define EXEC_RETURN_THREAD_MSP  0xFFFFFFF9  //return to thread mode and use main stack pointer
#define EXEC_RETURN_THREAD_PSP  0xFFFFFFFD  //return to trhead mode and use program stack pointer


void isr_soft0(void) __attribute__((interrupt,naked));
void proc_initialize(void);

void proc_request_context_switch(void);
void proc_exit(void);


#endif //__PROCESS_H
