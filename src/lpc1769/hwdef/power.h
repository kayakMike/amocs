#ifndef __HWDEF_POWER_H
#define __HWDEF_POWER_H

typedef struct{
    unsigned power_down              : 1;
    unsigned deep_power_down         : 1;
    unsigned brownout_reduced        : 1;
    unsigned brownout_global_disable : 1;
    unsigned brownout_reset_disable  : 1;
    unsigned                         : 5;
    unsigned sleep_entry             : 1;
    unsigned deep_sleep_entry        : 1;
    unsigned power_down_entry        : 1;
    unsigned deep_power_entry        : 1; 
    unsigned                         :20;
}PowerControlSystem;

#define POWER_CTL (*(volatile PowerControlSystem *)(0x400FC0C0))

typedef struct{
    unsigned              : 1;
    unsigned timer0       : 1;
    unsigned timer1       : 1;
    unsigned uart0        : 1;
    unsigned uart1        : 1;
    unsigned pwm1         : 1;
    unsigned i2c0         : 1;
    unsigned spi          : 1;
    unsigned rtc          : 1;
    unsigned ssp1         : 1;
    unsigned              : 1;
    unsigned adc          : 1;
    unsigned can1         : 1;
    unsigned can2         : 1;
    unsigned gpio         : 1;
    unsigned rit          : 1;
    unsigned mcpwm        : 1;
    unsigned qei          : 1;
    unsigned i2c1         : 1;
    unsigned ssp0         : 1;
    unsigned timer2       : 1;
    unsigned timer3       : 1;
    unsigned uart2        : 1;
    unsigned uart3        : 1;
    unsigned i2c2         : 1;
    unsigned i2s          : 1;
    unsigned              : 1;
    unsigned gpdma        : 1;
    unsigned enet         : 1;
    unsigned usb          : 1;
}PowerControlPeripheral;

#define PERIPHERAL_POWER (*(volatile PowerControlPeripheral *)(0x400FC0C4))


#endif // __HWDEF_POWER_H
