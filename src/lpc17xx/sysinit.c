#include "sysclock.h"
#include "ucom.h"
#include "thread.h"

//these are all referenced in the linker script
extern uint32_t _bss_start;
extern uint32_t _bss_end;
extern uint32_t _data_start;
extern uint32_t _data_end;
extern uint32_t _sidata;

void main(void);

//private core functions
void sysinit_initializeData (uint32_t *start, uint32_t *end, uint32_t *mem);
void sysinit_initializeBSS  (uint32_t *start, uint32_t *end);

//Reset ISR, the main entry point!
void isr_reset(void){
    sysinit_initializeData(&_data_start,&_data_end,&_sidata);
    sysinit_initializeBSS(&_bss_start,&_bss_end);
    sysclock_setMainClock120MHZ(); 
    
    //initialize drivers
    ucom_initializePort(UART0); 
    ucom_initializePort(UART2); 

    thread_initialize();

    systime_initialize();
    main00();
} 

/*
 * copies data section from flash to appropriate spot in the SRAM
 * data section is the 
 */
void sysinit_initializeData(uint32_t *start, uint32_t *end, uint32_t *mem){
    while(start < end){
        *start = *mem;
        start++;
        mem++;
    }
}

/*
 * function zeroes out the BSS section in the SRAM
 */
void sysinit_initializeBSS(uint32_t *start, uint32_t *end){
    while (start < end){
        *start++ = 0;
    }
}
