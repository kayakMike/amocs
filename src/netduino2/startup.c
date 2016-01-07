#include "system.h"
#include "micro_types.h"
#include "core.h"

void (*vectors[68])(void) __attribute__ ((section(".vectors")))={
    (void *)&_stack_init,
    Reset_Handler,            //1
    NMI_Handler,              //2
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
    SysTick_Handler,
};



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

void Reset_Handler(void){
    sysinit_memory();
    system_clock_initialize();
    gpio_setup();
    uart0_initialize();
//    sysinit_SysTick();
//    sysinit_stacks();
    Timer0_Initialize();
   
    main03();
} 

void NMI_Handler             (void){};
void HardFault_Handler       (void){};
void MemManage_Handler       (void){};
void BusFault_Handler        (void){};
void UsageFault_Handler      (void){};
void SVC_Handler             (void){};
void DebugMon_Handler        (void){};
void PendSV_Handler          (void){};
void WatchDog_Handler        (void){};

//void SysTick_Handler         (void){};
