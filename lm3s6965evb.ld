
ENTRY(Reset_Handler)
MEMORY{
    FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 256K
    SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 64K
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

