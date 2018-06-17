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

SECTIONS{

    .startup :
    {
        *(.stack_init)
        *(.isr_table)
    } > flash

    .text : 
    {
        startup.o(.text)
        *(.text)
        *(.rodata)
        . = ALIGN(4);
    } > flash
    _init_data = . ; 

    /* now lets startup the RAM  that needs initial values*/
    /* below section pretty much means the image in flash will have all the initial pieces of data
    *  but the program is linked to pull the data memory locations from the sram0
    */
    .data  : AT(_init_data)
    {
        _data_start = . ;
        *(.data)
        . = ALIGN(4);
        _data_end = . ;
    } > sram0

    .bss :
    {
        _bss_start = . ;
        *(.bss)
        _bss_end = . ;
    } > sram0

    PROVIDE(data_size = _data_end - _data_start);
    _bss_size  = SIZEOF(.bss);
}

/*_data_size = SIZEOF(.data) ;*/
/*_bss_size = SIZEOF(.bss);*/
