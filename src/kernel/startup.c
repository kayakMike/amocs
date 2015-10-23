#include "micro_types.h"


volatile uint32_t proc[4];
volatile uint32_t proc_index=0;
volatile uint32_t stack=0;



extern void main00(void);
extern void main01(void);
extern void main02(void);
extern void main03(void);


extern uint32_t _stack_init;
extern uint32_t _text_end;
extern uint32_t _bss_start;
extern uint32_t _bss_end;
extern uint32_t _data_start;
extern uint32_t _data_end;
extern uint32_t _datai_start;
extern uint32_t _sidata;

volatile uint32_t system_LongCount;

void Default_Handler         (void);
void Reset_Handler           (void);
void NMI_Handler             (void);
void HardFault_Handler       (void);
void MemManage_Handler       (void);
void BusFault_Handler        (void);
void UsageFault_Handler      (void);
void SVC_Handler             (void);
void DebugMon_Handler        (void);
void PendSV_Handler          (void);
void SysTick_Handler         (void) __attribute__ ((interrupt,naked));


void (*vectors[68])(void) __attribute__ ((section(".vectors")))={
    (void *)&_stack_init,
    Reset_Handler,
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,  
    BusFault_Handler,   
    UsageFault_Handler, 
    0,
    0,
    0,
    0,            
    SVC_Handler,        
    DebugMon_Handler,   
    0,                  
    PendSV_Handler,     
    SysTick_Handler
};


//SYSTIC STUFF
// Should be common for all ARM cortex-m3 cores, right?
typedef union{
    uint32_t val;
    struct {
        unsigned enableCounter     : 1;
        unsigned enableIrq         : 1;
        unsigned selectClockSource : 1; //0 is external, 1 is processor clock
        unsigned                   : 13;
        unsigned countFlag         : 1;
    }bits;
}SysTickControl;

#define SYSTICK_CONTROL  (*(volatile SysTickControl *)(0xE000E010))


typedef union{
    uint32_t val;
    struct {
        unsigned counterValue : 24;
        unsigned              :  8;
    }bits;
}SysTickCounterValue;

#define SYSTICK_RELOAD_VALUE  (*(volatile SysTickCounterValue *)(0xE000E014))
#define SYSTICK_CURRENT_VALUE (*(volatile SysTickCounterValue *)(0xE000E018))

typedef union{
    uint32_t val;
    struct {
        unsigned tenMillisec     : 24;  //value has counter number for 10 milliseconds
        unsigned                 :  6;
        unsigned isExact         :  1;
        unsigned noReference     :  1;  //if the systick is exact
    }bits;
}SysTickCalibration;

#define SYSTICK_CALIBRATION   (*(volatile SysTickCalibration *)(0xE000E018))
//END SYSTICK STUFF

void sysinit_SysTick(void){
    system_LongCount=0;
//    SYSTICK_RELOAD_VALUE.bits.counterValue=SYSTICK_CALIBRATION.bits.tenMillisec;
    SYSTICK_RELOAD_VALUE.bits.counterValue=(2040000-1);
    SYSTICK_CONTROL.bits.selectClockSource=1;
    SYSTICK_CONTROL.bits.enableIrq=1;
    SYSTICK_CONTROL.bits.enableCounter=1;
}



void sysinit_memory(void){
    uint32_t *data_begin   = &_data_start;
    uint32_t *data_end     = &_data_end;
    uint32_t *datai_begin  = &_sidata;
    uint32_t *bss_ptr      = &_bss_start;
    //INIT DATA:  copies data section from flash to ram
    while(data_begin < data_end){
        *data_begin = *datai_begin;
        data_begin++;
        datai_begin++;
    }
    //INIT BSS: loads a bunch of zeroes to bss section
    while (bss_ptr < &_bss_end){
        *bss_ptr++ = 0;
    }
}

void exit(void){
    while(true){

    }
}

void init_stack(uint32_t bot, uint32_t entry){

    uint32_t *stack=(uint32_t *)bot;
    stack[16]=0x01000000;
    stack[15]=(uint32_t)entry;
    stack[14]=(uint32_t)exit;
    stack[ 8]=0xFFFFFFF9;
    
}


void sysinit_stacks(void){
    //proc[0]=0x20010000;
    //notsureaboutthis....
    proc[1]=0x20003000-0x10; //4k stack space
    init_stack(0x20003000-0x10,(uint32_t)main01);
    proc[2]=0x20002000-0x10; //4k stack space
    init_stack(0x20002000-0x10,(uint32_t)main02);
    proc[3]=0x20001000-0x10; //4k stack space
    init_stack(0x20001000-0x10,(uint32_t)main03);
} 

void Reset_Handler(void){
    sysinit_memory();
//    sysinit_SysTick();
//    sysinit_stacks();

    main01();
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

void NMI_Handler             (void){};
void HardFault_Handler       (void){};
void MemManage_Handler       (void){};
void BusFault_Handler        (void){};
void UsageFault_Handler      (void){};
void SVC_Handler             (void){};
void DebugMon_Handler        (void){};
void PendSV_Handler          (void){};
//void SysTick_Handler         (void){};
