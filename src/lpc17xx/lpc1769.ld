/*ENTRY(isr_reset)*/

MEMORY{
    FLASH (rx)      : ORIGIN = 0x00000000, LENGTH = 512K
    SRAM (rwx)      : ORIGIN = 0x10000000, LENGTH = 32K
    ahb_sram0 (rwx) : ORIGIN = 0x2007C000, LENGTH = 16k
    ahb_sram1 (rwx) : ORIGIN = 0x20080000, LENGTH = 16k
}

_stack_init = ORIGIN(SRAM)+LENGTH(SRAM);
SECTIONS{
    .text : {
        KEEP(*(.vectors))
        *(.text*)
        *(.rodata*)
    } >FLASH

    _sidata = .;
    .data : AT (_sidata){
        _data_start = .;
        *(vtable)
        *(.data*)
        . = ALIGN (4);
        _data_end = .;
    } > SRAM

    .bss : {
        . = ALIGN(4);
        _bss_start = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _bss_end = .;
    } > SRAM
   
}
