#include "process.h"
#include "nvic.h"


//    uint32_t r4;      //1
//    uint32_t r5;      //2
//    uint32_t r6;      //3
//    uint32_t r7;      //4
//    uint32_t r8;      //5
//    uint32_t r9;      //6
//    uint32_t r10;     //7
//    uint32_t r11;     //8
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

typedef struct ProcessEntry{
    uint32_t base;
    uint32_t stack;
    uint32_t privilege;  //0 privilged 1 unprivileged
    uint8_t status;
}ProcessEntry;

#define PROC_MAX 4

volatile uint32_t save;
volatile uint32_t proc[4];
volatile uint32_t proc_index=0;
volatile uint32_t proc_total=0;

volatile ProcessEntry proc_table[PROC_MAX];


//switch context for the main stack pointer
//need to figure out which stack pointer the current context is using
//three possibilities:
//    thread mode msp   link register contains F9
//    thread mode psp   link register contains FD
//    handler mode msp  link register contains F1 
//    ... no tasks should be returning to handler mode, i think...
void isr_soft0(void){

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
        :[stack] "r" (&(proc_table[proc_index].stack)), [priv] "r" (proc_table[proc_index].privilege)
        : "r0" , "r1"
    );
    
    proc_index=(proc_index+1)%PROC_MAX;
  
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
        :[stack] "r" (&(proc_table[proc_index].stack)), [priv] "r" (proc_table[proc_index].privilege)
        : "r0" , "r1" 
    );
}

void proc_request_context_switch(void){
    //brain dead task switcher goes here
    //trigger the interrupt
    NVIC_SET_PENDING.soft0=1;
}


void proc_exit(void){
    while(true){
    }
}

uint32_t proc_initialize_stack(uint32_t loc, uint32_t entry){
//    loc=loc-sizeof(StackFrame);
    loc=loc-(16*4);
    StackFrame *stack=(StackFrame *)loc;
    stack->psr=0x21000000;
    stack->link=(uint32_t)proc_exit;
    stack->pc=entry;
}

void proc_initialize_stacks(void){
//    proc[0]=proc_initialize_stack(0x10008000,(uint32_t)main00);
    proc_table[0].base=0x10008000;
    proc_table[0].privilege=0;  
    proc_table[0].status=1;

//    proc[1]=proc_initialize_stack(0x10006000,(uint32_t)main01);
//    proc[2]=proc_initialize_stack(0x10004000,(uint32_t)main02);
//    proc[3]=proc_initialize_stack(0x10002000,(uint32_t)main03);

    proc_table[1].base=0x10006000;
    proc_table[1].stack=proc_initialize_stack(0x10006000,(uint32_t)main01);
    proc_table[1].privilege=0;
    proc_table[1].status=2;

    proc_table[2].base=0x10004000;
    proc_table[2].stack=proc_initialize_stack(0x10004000,(uint32_t)main02);
    proc_table[2].privilege=0;
    proc_table[2].status=1;

    proc_table[3].base=0x10002000;
    proc_table[3].stack=proc_initialize_stack(0x10002000,(uint32_t)main03);
    proc_table[3].privilege=1;
    proc_table[3].status=1;
} 


void proc_initialize(void){
    proc_initialize_stacks();
    NVIC_SET_ENABLE.soft0=1;
    NVIC_CLR_PENDING.soft0=1;
    NVIC_PRIORITY_CTL.soft0=0xF1;
}


