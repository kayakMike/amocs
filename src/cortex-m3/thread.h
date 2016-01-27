#ifndef __PROCESS_H
#define __PROCESS_H
#include "micro_types.h"

#define EXEC_RETURN_HANDLER     0xFFFFFFF1  //return to ISR handler mode and use main stack pointer 
#define EXEC_RETURN_THREAD_MSP  0xFFFFFFF9  //return to thread mode and use main stack pointer
#define EXEC_RETURN_THREAD_PSP  0xFFFFFFFD  //return to trhead mode and use program stack pointer
//(processes)
void main00(void);
void main01(void);
void main02(void);
void main03(void);



void isr_soft0(void) __attribute__((interrupt,naked));

void thread_initialize(void);
void thread_triggerContextSwitch(void);
void thread_exit(void);


#endif //__PROCESS_H
