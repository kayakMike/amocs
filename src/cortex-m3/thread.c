#include "thread.h"
#include "blink.h"
#include "nvic.h"


//order of registers that the cortex-m3 saves on the stack when an interrupt occurs
typedef struct StackFrame{
    uint32_t r4;      //0
    uint32_t r5;      //1
    uint32_t r6;      //2
    uint32_t r7;      //3
    uint32_t r8;      //4
    uint32_t r9;      //5
    uint32_t r10;     //6
    uint32_t r11;     //7
    uint32_t r0;      //8
    uint32_t r1;      //9
    uint32_t r2;      //10
    uint32_t r3;      //11
    uint32_t r12;     //12
    uint32_t link;    //13
    uint32_t pc;      //14
    uint32_t psr;     //15
}StackFrame;

typedef struct ThreadEntry{
    uint32_t base;
    uint32_t stack;
    uint32_t privilege;  //0 privilged 1 unprivileged
    uint8_t status;
}ThreadEntry;

#define THREAD_MAX 4

volatile uint32_t save;
volatile uint32_t thread_index=0;

volatile ThreadEntry thread_table[THREAD_MAX];

uint32_t thread_initializeStack(uint32_t loc, uint32_t entry)__attribute__((optimize("O0")));

//switch context for the main stack pointer
//need to figure out which stack pointer the current context is using
//three possibilities:
//    thread mode msp   link register contains F9
//    thread mode psp   link register contains FD
//    handler mode msp  link register contains F1 
//    ... no tasks should be returning to handler mode, i think...
void __attribute__((optimize("O0"))) isr_soft0(void){

    asm volatile(
        "cmp      %[priv] , #0           \n"
        "itttt    eq                     \n"
        "mrseq    r0  , msp              \n"
        "stmdbeq  r0! , {r4-r11}         \n"  // r4 through r11 is the contex to save
        "msreq    msp , r0               \n"
        "isbeq                           \n"
       
        "itttt    ne                     \n"
        "mrsne    r0  , psp              \n" 
        "stmdbne  r0! , {r4-r11}         \n"  // r4 through r11 is the contex to save
        "msrne    psp , r0               \n"
        "isbne                           \n"
       
        "str      r0  , [%[stack]]       \n"
        :
        :[stack] "r" (&(thread_table[thread_index].stack)), [priv] "r" (thread_table[thread_index].privilege)
        : "r0" , "r1"
    );
    
    thread_index=(thread_index+1)%THREAD_MAX;
  
    asm volatile(
        //restore the stack
        "ldr    r0   , [%[stack]]      \n"
        "ldmia  r0!  , {r4-r11}        \n"
        //check if priv is zero
        "cmp    %[priv] , #0           \n"
        //then restor main stack pointer and set EXEC_RETURN_MSP
        "ittt   eq                     \n"
        "msreq  msp  , r0              \n"
        "isbeq                         \n"
        "ldreq  r14  , =0xFFFFFFF9     \n"  
        //if priv is not zero restore prog stack pointer and set EXEC_RETURN_PSP
        "ittt   ne                     \n"
        "msrne  psp  , r0              \n"
        "isbne                         \n"
        "ldrne  r14  , =0xFFFFFFFD     \n"  
        //end the ISR
        "bx     r14                    \n" 
        :
        :[stack] "r" (&(thread_table[thread_index].stack)), [priv] "r" (thread_table[thread_index].privilege)
        : "r0" , "r1" 
    );
}

void thread_triggerContextSwitch(void){
    //brain dead task switcher goes here
    //trigger the interrupt
//    blink_toggleOutput(0,20);
    NVIC_SET_PENDING.soft0=1;
}


void thread_exit(void){
    while(true){
    }
}

uint32_t thread_initializeStack(uint32_t loc, uint32_t entry){
//    loc=loc-sizeof(StackFrame);
    loc=loc-(16*4);
    StackFrame *stack=(StackFrame *)loc;
    stack->psr=0x21000000;
    stack->link=(uint32_t)thread_exit;
    stack->pc=entry;
}

void  thread_initializeThreadTable(void){
//    thread[0]=thread_initialize_stack(0x10008000,(uint32_t)main00);
    thread_table[0].base=0x10008000;
    thread_table[0].privilege=0;  
    thread_table[0].status=1;

    thread_table[1].base=0x10006000;
    thread_table[1].stack=thread_initializeStack(0x10006000,(uint32_t)main01);
    thread_table[1].privilege=0;
    thread_table[1].status=2;

    thread_table[2].base=0x10004000;
    thread_table[2].stack=thread_initializeStack(0x10004000,(uint32_t)main02);
    thread_table[2].privilege=0;
    thread_table[2].status=1;

    thread_table[3].base=0x10002000;
    thread_table[3].stack=thread_initializeStack(0x10002000,(uint32_t)main03);
    thread_table[3].privilege=1;
    thread_table[3].status=1;
} 


void thread_initialize(void){
    thread_initializeThreadTable();
    NVIC_CLR_PENDING.soft0=1;
    NVIC_SET_ENABLE.soft0=1;
    NVIC_PRIORITY_CTL.soft0=0x1F;
}


