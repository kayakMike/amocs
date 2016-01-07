#include "system.h"
#include "hwdef_systick.h"
//#include "core_isr.h"

//some simple ideas...
typedef enum{
    INITIALIZED,
    STARTED,
    WAITING,
    STOPPED,
    UNINITIALIZED
}ProcessState;

//
typedef struct{
    uint32_t id;
    uint32_t stack;
    ProcessState state;
}ProcessEntry;    


volatile uint32_t proc[4];
volatile uint32_t proc_index=0;
volatile uint32_t stack=0;
volatile uint32_t system_LongCount=0;

#define SYSTICK_IRQ_PRIORITY (*(volatile uint8_t *)(0xE000E400))

void SysTick_ISR(void) __attribute__((interrupt,naked));

//This 
void SysTick_ISR(void){
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

void exit(void){
    while(true){

    }
}

//
void init_stack(uint32_t bot, uint32_t entry){
    uint32_t *stack=(uint32_t *)bot;
    stack[16]=0x01000000;
    stack[15]=(uint32_t)entry;
    stack[14]=(uint32_t)exit;
    stack[ 8]=0xFFFFFFF9;
}

void initialize_stacks(void){
    proc[1]=   0x10006000-0x10; //4k stack space
    init_stack(0x10006000-0x10,(uint32_t)main01);
    proc[2]=   0x10004000-0x10; //4k stack space
    init_stack(0x10004000-0x10,(uint32_t)main02);
    proc[3]=   0x10002000-0x10; //4k stack space
    init_stack(0x10002000-0x10,(uint32_t)main03);
} 

void initialize_systick(void){
    SYSTICK_RELOAD_VALUE.bits.counterValue=(1200000-1);
    SYSTICK_CONTROL.bits.selectClockSource=1;
    SYSTICK_CONTROL.bits.enableIrq=1;
    SYSTICK_CONTROL.bits.enableCounter=1;
    SYSTICK_IRQ_PRIORITY=0x00;
}
