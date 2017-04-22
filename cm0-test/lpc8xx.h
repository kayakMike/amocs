#include "types.h"

#ifndef __LPC8xx_H_
#define __LPC8XX_H_

//MAIN POWER STUFF
typedef struct power_configuration_register {
    unsigned irc_out      : 1;  // 0: powered 1: powerdown reset: 0
    unsigned irc          : 1;
    unsigned flash        : 1;
    unsigned bod          : 1;
    unsigned adc          : 1;
    unsigned xtal_osc     : 1; 
    unsigned watchdog_osc : 1; 
    unsigned system_pll   : 1;
    unsigned              : 4;
    unsigned              : 3;
    unsigned analog_cmp   : 1;
    unsigned              :16;
}PowerConfigurationRegister;
#define POWER_CONFIGURATION_REGISTER (*(volatile PowerConfigurationRegister *)(0x40048238))

//PERIPHERAL CLOCKS
typedef struct system_clock_control {
    unsigned sys        : 1;
    unsigned rom        : 1;
    unsigned ram0_1     : 1;
    unsigned flash_reg  : 1;
    unsigned flash      : 1;
    unsigned i2c0       : 1;
    unsigned gpio       : 1;
    unsigned swm        : 1;
    unsigned sct        : 1;
    unsigned wkt        : 1;
    unsigned mrt        : 1;
    unsigned spi0       : 1;
    unsigned spi1       : 1; 
    unsigned crc        : 1;
    unsigned uart0      : 1;
    unsigned uart1      : 1;
    unsigned uart2      : 1;
    unsigned wwdt       : 1;
    unsigned iocon      : 1;
    unsigned acmp       : 1;
    unsigned i2c1       : 1;
    unsigned i2c2       : 1;
    unsigned i2c3       : 1;
    unsigned adc        : 1;
    unsigned            : 1;
    unsigned mtp        : 1;
    unsigned            : 2;
    unsigned dma        : 1;
    unsigned            : 2;
}SystemClockControl;
#define SYSTEM_CLOCK_CONTROL (*(volatile SystemClockControl *)(0x40048080))

//IOCON
typedef struct pin_config_register {
    unsigned                       : 3; //
    unsigned mode                  : 2;
    unsigned hysteresis            : 1;
    unsigned invert                : 1;
    unsigned                       : 3;
    unsigned open_drain            : 1; 
    unsigned s_mode                : 2;
    unsigned clk_divide            : 3;
    unsigned                       :16;
}PinConfigRegister; 
#define PIO0_17 (*(volatile PinConfigRegister *)(0x40044000))
#define PIO0_13 (*(volatile PinConfigRegister *)(0x40044004))
#define PIO0_12 (*(volatile PinConfigRegister *)(0x40044008))
#define PIO0_05 (*(volatile PinConfigRegister *)(0x4004400C))
#define PIO0_04 (*(volatile PinConfigRegister *)(0x40044010))
#define PIO0_03 (*(volatile PinConfigRegister *)(0x40044014))
#define PIO0_02 (*(volatile PinConfigRegister *)(0x40044018))
#define PIO0_11 (*(volatile PinConfigRegister *)(0x4004401C))
#define PIO0_10 (*(volatile PinConfigRegister *)(0x40044020))
#define PIO0_16 (*(volatile PinConfigRegister *)(0x40044024))
#define PIO0_15 (*(volatile PinConfigRegister *)(0x40044028))
#define PIO0_01 (*(volatile PinConfigRegister *)(0x4004402C))
//RESERVED:                                      0x40044030
#define PIO0_09 (*(volatile PinConfigRegister *)(0x40044034))
#define PIO0_08 (*(volatile PinConfigRegister *)(0x40044038))
#define PIO0_07 (*(volatile PinConfigRegister *)(0x4004403C))
#define PIO0_06 (*(volatile PinConfigRegister *)(0x40044040))
#define PIO0_00 (*(volatile PinConfigRegister *)(0x40044044))
#define PIO0_14 (*(volatile PinConfigRegister *)(0x40044048))
//RESERVED:                                      0x4004404C
#define PIO0_28 (*(volatile PinConfigRegister *)(0x40044050))
#define PIO0_27 (*(volatile PinConfigRegister *)(0x40044054))
#define PIO0_26 (*(volatile PinConfigRegister *)(0x40044058))
#define PIO0_25 (*(volatile PinConfigRegister *)(0x4004405C))
#define PIO0_24 (*(volatile PinConfigRegister *)(0x40044060))
#define PIO0_23 (*(volatile PinConfigRegister *)(0x40044064))
#define PIO0_22 (*(volatile PinConfigRegister *)(0x40044068))
#define PIO0_21 (*(volatile PinConfigRegister *)(0x4004406C))
#define PIO0_20 (*(volatile PinConfigRegister *)(0x40044070))
#define PIO0_19 (*(volatile PinConfigRegister *)(0x40044074))
#define PIO0_18 (*(volatile PinConfigRegister *)(0x40044078))

typedef struct pin_enable_0 {
    unsigned acmp_i1            : 1;
    unsigned acmp_i2            : 1;
    unsigned acmp_i3            : 1;
    unsigned acmp_i4            : 1;
    unsigned swclk              : 1;
    unsigned swdio              : 1;
    unsigned xtalin             : 1;
    unsigned xtalout            : 1;
    unsigned resetn             : 1;
    unsigned clkin              : 1;  
    unsigned vddcmp             : 1;
    unsigned i2c0_sda           : 1;
    unsigned i2c0_scl           : 1;
    unsigned adc_0              : 1;
    unsigned adc_1              : 1;
    unsigned adc_2              : 1;
    unsigned adc_3              : 1;    
    unsigned adc_4              : 1;   
    unsigned adc_5              : 1;
    unsigned adc_6              : 1;
    unsigned adc_7              : 1;
    unsigned adc_8              : 1;
    unsigned adc_9              : 1;
    unsigned adc_10             : 1;
    unsigned adc_11             : 1; 
    unsigned                    : 7;
}PinEnable;
#define PIN_ENABLE (*(volatile PinEnable *)(0x4000C1C0))

typedef struct system_oscillator_control {
    unsigned bypass            : 1;
    unsigned frequency_range   : 1;
    unsigned                   :30;
}SystemOscillatorControl;
#define SYSTEM_OSCILLATOR_CONTROL (*(volatile SystemOscillatorControl *)(0x40048020))

typedef struct pin_assign_00{
    unsigned u0_txd_o   : 8;
    unsigned u0_rxd_i   : 8;
    unsigned u0_rts_o   : 8;
    unsigned u0_cts_i   : 8;
}PinAssign_00;
#define PIN_ASSIGN_00  (*(volatile PinAssign_00 *)(0x4000C000))

typedef struct pin_assign_11{
    unsigned adc_pin_trigger1_i   : 8;
    unsigned acmp_o_o             : 8;
    unsigned clockout_o           : 8;
    unsigned gpio_int_bmat_o      : 8;
}PinAssign_11;
#define PIN_ASSIGN_11  (*(volatile PinAssign_11 *)(0x4000C02C))

typedef struct clock_out_select {
    unsigned select                :2;
    unsigned                       :30;
}ClockOut_Select;
#define CLOCK_OUT_SELECT (*(volatile ClockOut_Select *)(0x400480E0))

typedef struct clock_out_update_enable {
    unsigned update                : 1;
    unsigned                       :31;
}ClockOut_Update_Enable;
#define CLOCK_OUT_UPDATE_ENABLE (*(volatile ClockOut_Update_Enable *)(0x400480E4))
#define CLOCK_OUT_DIVIDER (*(volatile uint8_t *)(0x400480E8))


//GPIO STUFF HERE
#define PORT0_DIR (*(volatile uint32_t *)(0xA0002000))
#define PORT0_VAL (*(volatile uint32_t *)(0xA0002100))
#define PORT0_SET (*(volatile uint32_t *)(0xA0002200))
#define PORT0_CLR (*(volatile uint32_t *)(0xA0002280))
#define PORT0_NOT (*(volatile uint32_t *)(0xA0002300))

#endif //__LPC8XX_H_
