#include "system.h"
#include "hwdef_systick.h"

uint32_t system_LongCount=0;

extern uint32_t proc[4];
extern uint32_t proc_index;
extern uint32_t stack;


void sysinit_SysTick(void){
//    SYSTICK_RELOAD_VALUE.bits.counterValue=(1000000-1);
    SYSTICK_CONTROL.bits.selectClockSource=1;
    SYSTICK_CONTROL.bits.enableIrq=1;
    SYSTICK_CONTROL.bits.enableCounter=1;
}

void SysTick_Handler(void){
    asm volatile(
        "ldr       r1,  .saveContext               \n"
        "mrs       r0,  msp                        \n"
        "stmdb     r0!, {r4-r11,r14}               \n"
        "str       r0,  [r1]                       \n"
        "msr       msp, r0                         \n"
        "isb                                       \n"
        "dsb                                       \n"
        ".saveContext: .word stack                 \n"
    );
    system_LongCount++;

    //brain dead task switching!
    proc[proc_index]=stack;
    proc_index=(proc_index+1)%4;
    stack=proc[proc_index];

    asm volatile(
        "ldr       r1,  .loadContext               \n"
        "ldr       r0,  [r1]                       \n"
        "ldmia     r0!, {r4-r11,r14}               \n"
        "msr       msp, r0                         \n"
        "isb                                       \n"
        "dsb                                       \n"
        "bx        r14                             \n"
        ".loadContext: .word stack                 \n"
    );
}


