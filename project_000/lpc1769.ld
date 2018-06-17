OUTPUT_FORMAT ("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
/*ENTRY(isr_reset)*/
MEMORY
{
    /* Non Volatile Memory */
    flash (rx)  : ORIGIN = 0x00000000, LENGTH = 512K
    /* Main sram bank */
    sram0 (rwx) : ORIGIN = 0x10000000, LENGTH = 32K
    /* advanced high performance bus ram banks */
    sram1 (rwx) : ORIGIN = 0x2007C000, LENGTH = 16k
    sram2 (rwx) : ORIGIN = 0x20080000, LENGTH = 16k
}

/*TODO: change this to support the Memory protection Unit */
/*for now, just put the kernel stack way at the end of the sram bank */
/* stack_address = ORIGIN(sram) + LENGTH(sram); */

SECTIONS{

    .text : 
    {
        KEEP(*(.isr_table))
        *(.text)
        *(.rodata)
    } > flash
    _initial_data = .; 

    /* now lets startup the RAM */
    /*. = ORIGIN(sram0)         */
    .data  : AT(_initial_data)
    {
        _data = . ;
        *(.data)
        . = ALIGN(4);
        _data_end = .;
        _data_size = SIZEOF(.data) ;
    } > sram0

    .bss :
    {
        _bss = . ;
        *(.bss)
        _bss_size = SIZEOF(.bss);
    } > sram0
}


/*
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
   

    .stack_address :
    {
        *(*.stack_address)
    } > flash

    .isr_table : 
    {
        KEEP(*(*.isr_table .isr_table.*))
    } > flash

    .text : {
        *(.text)
    } > flash
        
    .rodata : { 
        *(.rodata*)
    } > flash




   */
