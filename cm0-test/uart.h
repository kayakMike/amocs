#ifndef __UART_H
#define __UART_H
#include "types.h"

typdef struct uart_config{
    uint32_t sys_clk_in_hz; // main clock/UARTCLKDIV in Hz
    uint32_t baudrate_in_hz; // Baudrate in hz
    uint8_t config; 
    //bit 1:0
    // 00: 7 bits length, 01: 8 bits lenght, others: reserved
    //bit3:2
    // 00: No Parity, 01: reserved, 10: Even, 11: Odd
    //bit4
    // 0: 1 Stop bit, 1: 2 Stop bits
    uint8_t sync_mod; //bit0: 0(Async mode), 1(Sync mode)
    //bit1: 0(Un_RXD is sampled on the falling edge of SCLK)
    // 1(Un_RXD is sampled on the rising edge of SCLK)
    //bit2: 0(Start and stop bits are transmitted as in asynchronous mode)
    // 1(Start and stop bits are not transmitted)
    //bit3: 0(the UART is a slave on Sync mode)
    // 1(the UART is a master on Sync mode)
    uint16_t error_en; //Bit0: OverrunEn, bit1: UnderrunEn, bit2: FrameErrEn,
    // bit3: ParityErrEn, bit4: RxNoiseEn
}UART_CONFIG;

typedef void *UART_HANDLE_T;   // define TYPE for uart handle pointer
typedef void (*UART_CALLBK_T)(uint32_t err_code, uint32_t n);

typedef struct uart_parameter{ 
    // parms passed to uart driver function
    uint8_t *buffer ; 
    // The pointer of buffer.
    // For uart_get_line function, buffer for receiving data.
    // For uart_put_line function, buffer for transmitting data.
    uint32_t size; 
    // [IN] The size of buffer.
    // [OUT] The number of bytes transmitted/received.
    uint16_t transfer_mode ;
    // 0x00: For uart_get_line function, transfer without termination.
    //       For uart_put_line function, transfer without termination.
    // 0x01: For uart_get_line function, stop transfer when <CR><LF> are
    //       received.  For uart_put_line function, transfer is stopped after
    //       reaching \0. <CR><LF> characters are sent out after that.
    // 0x02: For uart_get_line function, stop transfer when <LF>
    //       is received. For uart_put_line function, transfer is stopped after
    //       reaching \0. A <LF> character is sent out after that.
    // 0x03: For uart_get_line function, RESERVED. For uart_put_line function, 
    //       transfer is stopped after reaching \0.
    uint16_t driver_mode;
    // 0x00: Polling mode, function is blocked until transfer is finished.
    // 0x01: Intr mode, function exit immediately, callback function is invoked
    //       when transfer is finished.
    // 0x02: RESERVED
    UART_CALLBK_T callback_func_pt; // callback function
}UART_PARAM_T;    

typedef struct uartd_api{ 
    uint32_t      (*uart_get_mem_size)(void);
    UART_HANDLE_T (*uart_setup)(uint32_t base_addr, uint8_t *ram);
    uint32_t      (*uart_init)(UART_HANDLE_T handle, UART_CONFIG_T *set);
    uint8_t       (*uart_get_char)(UART_HANDLE_T handle);
    void          (*uart_put_char)(UART_HANDLE_T handle, uint8_t data);
    uint32_t      (*uart_get_line)(UART_HANDLE_T handle, UART_PARAM_T * param);
    uint32_t      (*uart_put_line)(UART_HANDLE_T handle, UART_PARAM_T * param);
    void          (*uart_isr)(UART_HANDLE_T handle);
} UARTD_API_T;
#define ROM_DRIVER_BASE (0x1FFF1FF8)
//#define LPC_UART_API ((UARTD_API_T *) ((*(ROM_API_T * *) (ROM_DRIVER_BASE))->pUARTD))
    
#define UARTD_API_T  ((void *)(ROM_DRIVER_BASE + 0x24))
#define UART_BASE uint32_t  0x40064000


/*
uint32_t (*uart_get_mem_size)( void);                                 //ramsize_in_bytes UART get memory size Table 347
UART_HANDLE_T* (*uart_setup)(uint32_t base_addr, uint8_t *ram);       //UART set-up Table 348
uint32_t (*uart_init)(UART_HANDLE_T* handle, UART_CONFIG set);        //UART init Table 349
uint8_t (*uart_get_char)(UART_HANDLE_T* handle);                      //UART get character Table 350
void (*uart_put_char)(UART_HANDLE_T* handle, uint8_t data);           //UART put character Table 351
uint32_t (*uart_get_line)(UART_HANDLE_T* handle, UART_PARAM_T param); //UART get line Table 352
uint32_t (*uart_put_line)(UART_HANDLE_T* handle, UART_PARAM_T param); //UART put line Table 353
void (*uart_isr)(UART_HANDLE_T* handle);                              // UART interrupt service routine Table 354
*/
    
#endif // __UART_H    
    
    
    
    












