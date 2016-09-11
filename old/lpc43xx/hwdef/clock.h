#ifndef __clock_defs_h
#define __clock_defs_h 

#include "system_types.h"
/** 
 * @brief UM10503 section 12.6.2 Table 124 Crystal Oscillator Control Register
 * @var inputDisable   
 * @var crystalBypassEnable
 * @var highFrequencyEnable 
 *
 * @warning
 *    dont change inputDisable and crystalBypassEnable at with the same memory write
 *
 */
struct ExternalOscillatorControl{                       
    unsigned inputDisable         : 1;  //!< disable external oscillator input, default 1
    unsigned crystalBypassEnable  : 1;  //!< hardware has clock driven by a clock input rather than crystal, default 0
    unsigned highFrequencyEnable  : 1;  //!< input frequency is above 15MHz, default 1
    unsigned                      :28;  
};

/** 
 * @brief memory location*/
#define CLOCK_EXTERNAL_OSCILLATOR (*(volatile struct ExternalOscillatorControl *)(0x40050018))

/**
 * @struct BaseClockControl 
 * @brief UM10503 12.6.13 
 *
 * Table 143 BASE_M4_CLK to BASE_UART3_CLK control registers 
 *     
 * @var BaseClockControl::clockSelect
 *    values for the clock select.  maybe make these into an enum
 *    + 0x00 32 kHz oscillator
 *    + 0x01 IRC (default)
 *    + 0x02 ENET_RX_CLK
 *    + 0x03 ENET_TX_CLK
 *    + 0x04 GP_CLKIN
 *    + 0x06 Crystal oscillator
 *    + 0x08 PLL0AUDIO
 *    + 0x09 PLL1
 *    + 0x0C IDIVA
 *    + 0x0D IDIVB
 *    + 0x0E IDIVC
 *    + 0x0F IDIVD
 *    + 0x10 IDIVE
 *
 * @var BaseClockControl::powerDisable
 * @brief setting this bit to 1 turns the related clock off
 */
struct BaseClockControl{
    unsigned powerDisable       : 1;  //!< disable power to the clock
    unsigned                    :10;  
    unsigned autoBlockEnable    : 1;  //!< enable autoblocking feature to the specific clock
    unsigned                    :12; 
    unsigned clockSelect        : 5;  //!< select the input clock
    unsigned                    : 3; 
};     
#define BASE_M4_CLOCK    (*(volatile struct BaseClockControl *)(0x4005006C))
#define BASE_SPI_CLOCK   (*(volatile struct BaseClockControl *)(0x40050074))
#define BASE_UART0_CLOCK (*(volatile struct BaseClockControl *)(0x4005009C))


/**
 * @struct MainPLLControl
 * @brief 12.6.5.2 PLL1 control register
 * Table 135. PLL1_CTRL register (PLL1_CTRL, address 0x4005 0044) bit description
 * ### Settings for Integer Mode
 * \f[ F_{clkcout}=M*\frac{F_{clckin}}{N} \f]
 *
 * @var MainPLLControl::postDivisorSelect  
 *    - 0x0 1
 *    - 0x1 2 (default value)
 *    - 0x2 4
 *    - 0x3 8
 * @var MainPLLControl::preDivisor
 *    - 0x0 1
 *    - 0x1 2
 *    - 0x2 3 (default)
 *    - 0x3 4
 * @var MainPLLControl::preFeedbackDivider
 *    - 00000000 = 1
 *    - 00000001 = 2
 *    - ...
 *    - 11111111 = 256
 * @var MainPLLControl::inputClockSelect
 *    - 0x00 32 kHz oscillator
 *    - 0x01 IRC (default)
 *    - 0x02 ENET_RX_CLK
 *    - 0x03 ENET_TX_CLK
 *    - 0x04 GP_CLKIN
 *    - 0x05 Reserved
 *    - 0x06 Crystal oscillator
 *    - 0x07 PLL0USB
 *    - 0x08 PLL0AUDIO
 *    - 0x09 Reserved
 *    - 0x0A Reserved
 *    - 0x0C IDIVA
 *    - 0x0D IDIVB
 *    - 0x0E IDIVC
 *    - 0x0F IDIVD
 *    - 0x10 IDIVE
 */
struct MainPLLControl{
    unsigned powerDisable       : 1;  //!< set this to 1 to disable the PLL1 power
    unsigned bypassEnable       : 1;  //!< set this to 1 to connect the input directly to the output bypassing the PLL completely
    unsigned                    : 1;
    unsigned                    : 3;
    unsigned feedbackSelect     : 1;  //!< select either the cco or something else for feedback control of the PLL
    unsigned directCcoEnable    : 1;  //!< enable direct mode
    unsigned postDivisorSelect  : 2;  //!< postdivisor p selection values for the PLL setting equasions
    unsigned                    : 1; 
    unsigned autoBlockEnable    : 1;
    unsigned preDivisor         : 2;  //!< predivisor N selection values for PLL settings equations
    unsigned                    : 2;
    unsigned preFeedbackDivisor : 8;  //!< feedback divisor m values for PLL settings equasions
    unsigned inputClockSelect   : 5;  //!< input clock clock selection values field
    unsigned                    : 3;
};
#define PLL1_CONTROL  (*(volatile struct MainPLLControl *)(0x40050044))


/* 12.6.5.1 PLL1 status register Table 134
 */
struct MainPLLStatus{
    unsigned lockAcquired     : 1;  //0
    unsigned                  :31;  //1-31 the rest of them...
};
#define PLL1_STATUS  (*(volatile struct MainPLLStatus *)(0x40050040))


#endif //__clock_defs_h

