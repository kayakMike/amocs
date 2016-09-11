#ifndef __HWDEF_SPI_H
#define __HWDEF_SPI_H

/**
 * @brief 42.6.1 SPI Control Register Table 985: SPI Control Register (CR - address 0x4010 0000)
 *
 */
struct SpiConfiguration{
    unsigned                    : 2;
    unsigned txSizeEnable       : 1; //!< 0 8 bit tx     1 see fields 11:8
    unsigned clockPhase         : 1; //!< 0 FIRST Edge     1 Second Edge
    unsigned clockPolarity      : 1; //!< 0 SCK active HI  1 SCK active LO
    unsigned masterEnable       : 1; //!< 0 is SLave       1 is Master
    unsigned endianSelect       : 1; //!< 0 is MSB First   1 is LSB first
    unsigned interruptEnable    : 1; //!< 0 no interrupt   1 interrupt enabled
    unsigned txSizeSelect       : 4; //!< 0 see bit 2    0x8 --> 8 fields 0x9 --> 9 fields...
    unsigned                    :19; //!< reserved
};
#define SPI_CONTROL  (*(volatile struct SpiConfiguration*)     (0x40100000))


/**
 * @brief 42.6.2 SPI Status Register Table 986: SPI Status Register (SR - address 0x4010 0004) bit description
 *
 */
struct SpiStatus{
    unsigned              : 3; 
    unsigned slaveAbort   : 1; 
    unsigned modeFault    : 1; 
    unsigned readOverrun  : 1; 
    unsigned writeCollide : 1; 
    unsigned txComplete   : 1; 
    unsigned              :24; //reserved
};
#define SPI_STATUS  (*(volatile struct SpiStatus*)      (0x40100004))

/**
 * 42.6.3 SPI Data Register Table 987: SPI Data Register (DR - address 0x4010 0008) bit description
 *
 */
struct SpiTransmitBuffer{
    unsigned low      : 8; //!< least significant byte for a transmit
    unsigned high     : 8; //!< most significant byte for a transmit
    unsigned          :16; //!< reserved
};
#define SPI_TRANSMIT_BUFFER  (*(volatile struct SpiTransmitBuffer*)        (0x40100008))


/**
 *  @brief 42.6.4 SPI Clock Counter Register
 *  Table 988: SPI Clock Counter Register (CCR - address 0x4010 000C) bit description
 *     Clock divisor must be an even number greater than 8
 *     functionally controls the clock speed of the interface PCLK_SPI/clockDivisor
 *     only has relevance in master mode
 *     Example:  if the BASE_SPI_CLOCK is 204 MHz and the CLOCK DIVISOR is 204, then the 
 *     SCK will run at 1 MHz.  I think...
 */
struct SpiClockDivisor{
    unsigned clockDivisor : 8; //!< must be an even number greater than 8, divides the base spi clock
    unsigned              :24; 
};
#define SPI_CLOCK_DIVISOR  (*(volatile struct SpiClockDivisor*)(0x4010000C))


//not so sure about these, test interfaces, i guess
//#define SPI_TCR  (*(volatile SpiTestControl*) (0x40100010))
//#define SPI_TSR  (*(volatile SpiTestStatus*)  (0x40100014))

/**
 * @brief no description.  context may be slave mode, not sure
 */
struct SpiInterruptFlag{
    unsigned interruptSet     : 1;  //!< interrupt has been generated from the spi Interface 
    unsigned                  :31; 
};
#define SPI_INTERRUPT_FLAG  (*(volatile SpiInterruptFlag*)   (0X4010001C))

#endif //__HWDEF_SPI_H
