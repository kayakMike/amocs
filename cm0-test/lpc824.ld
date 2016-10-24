/*ENTRY(isr_reset)*/

MEMORY{
    FLASH (rx)      : ORIGIN = 0x00000000, LENGTH = 32K
/*  SRAM  (rwx)     : ORIGIN = 0x10000000, LENTGH = 8K */
    SRAM0 (rwx)     : ORIGIN = 0x10000000, LENGTH = 4K
    SRAM1 (rwx)     : ORIGIN = 0x10001000, LENGTH = 4K
}

/* put stack at the end of SRAM1 */
_stack_init = ORIGIN(SRAM0) + LENGTH(SRAM0) + LENGTH(SRAM1);
SECTIONS{
    .text : {
        KEEP(*(.vectors))
        *(.text*)
        *(.rodata*)
    } >FLASH

    _sidata = .;
    /* data and BSS go in SRAM0 */
    .data : AT (_sidata){
        _data_start = .;
        *(vtable)
        *(.data*)
        . = ALIGN (4);
        _data_end = .;
    } > SRAM0

    .bss : {
        . = ALIGN(4);
        _bss_start = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _bss_end = .;
    } > SRAM0
   
}
