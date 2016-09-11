#include "types.h"

//these are all referenced in the linker script
//and describe the bss and data sections
extern uint32_t _bss_start;
extern uint32_t _bss_end;
extern uint32_t _data_start;
extern uint32_t _data_end;
extern uint32_t _sidata;

void boot_data(uint32_t *start, uint32_t *end, uint32_t *mem);
void boot_bss(uint32_t *start, uint32_t *end);

void main(uint32_t argc, uint8_t **argv);


/*
 * copies data section from flash to appropriate spot in the SRAM
 * data section is the 
 */
void boot_data(uint32_t *start, uint32_t *end, uint32_t *mem)
{
    while(start < end)
    {
        *start = *mem;
        start++;
        mem++;
    }
}

/* function zeroes out the BSS section in the SRAM
 *
 */
void boot_bss(uint32_t *start, uint32_t *end)
{
    while (start < end)
    {
        *start++ = 0;
    }
}


/*  The system is started in the isr reset handler
 * 
 */
void isr_reset(void)
{
    boot_data(&_data_start, &_data_end, &_sidata);
    boot_bss(&_bss_start, &_bss_end);
    //call main
    main(0, NULL);

    while(TRUE)
    {
        //do nothing
        //this is what the system does if main ever exits
    }
} 

