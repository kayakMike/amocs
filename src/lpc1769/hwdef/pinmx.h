#ifndef __HWDEF_PINMX_H
#define __HWDEF_PINMX_H


typedef struct{          //|FUNC0    FUNC1         FUNC2    FUNC3
    unsigned p0_00  : 2; //|P0.00    RD1           TXD3     SDA1     offset: 0x00   reg0
    unsigned p0_01  : 2; //|P0.01    TD1           RXD3     SCL1
    unsigned p0_02  : 2; //|P0.02    TXD0          AD0.7    Reserved 
    unsigned p0_03  : 2; //|P0.03    RXD0          AD0.6    Reserved
    unsigned p0_04  : 2; //|P0.04    I2SRX_CLK     RD2      CAP2.0 
    unsigned p0_05  : 2; //|P0.05    I2SRX_WS      TD2      CAP2.1
    unsigned p0_06  : 2; //|P0.06    I2SRX_SDA     SSEL1    MAT2.0
    unsigned p0_07  : 2; //|P0.07    I2STX_CLK     SCK1     MAT2.1     
    unsigned p0_08  : 2; //|P0.08    I2STX_WS      MISO1    MAT2.2
    unsigned p0_09  : 2; //|P0.09    I2STX_SDA     MOSI1    MAT2.3
    unsigned p0_10  : 2; //|P0.10    TXD2          SDA2     MAT3.0
    unsigned p0_11  : 2; //|P0.11    RXD2          SCL2     MAT3.1
    unsigned        : 2; //| 0x03                 
    unsigned        : 2; //|Reserved Reserved      Reserved Reserved
    unsigned        : 2; //|                      
    unsigned p0_15  : 2; //|P0.15    TXD1          SCK0       SCK         
    unsigned p0_16  : 2; //|P0.16    RXD1          SSEL0      SSEL 0x04 reg1
    unsigned p0_17  : 2; //|P0.17    CTS1          MISO0      MISO 
    unsigned p0_18  : 2; //|P0.18    DCD1          MOSI0      MOSI
    unsigned p0_19  : 2; //|P0.19    DSR1          Reserved   SDA1
    unsigned p0_20  : 2; //|P0.20    DTR1          Reserved   SCL1 0x05
    unsigned p0_21  : 2; //|P0.21    RI1           Reserved   RD1
    unsigned p0_22  : 2; //|P0.22    RTS1          Reserved   TD1
    unsigned p0_23  : 2; //|P0.23    AD0.0         I2SRX_CLK  CAP3.0
    unsigned p0_24  : 2; //|P0.24    AD0.1         I2SRX_WS   CAP3.1 0x06
    unsigned p0_25  : 2; //|P0.25    AD0.2         I2SRX_SDA  TXD3
    unsigned p0_26  : 2; //|P0.26    AD0.3         AOUT RXD3 
    unsigned p0_27  : 2; //|P0.27    SDA0          USB_SDA    Reserved
    unsigned p0_28  : 2; //|P0.28    SCL0          USB_SCL    Reserved 0x07
    unsigned p0_29  : 2; //|P0.29    USB_D        Reserved   Reserved
    unsigned p0_30  : 2; //|P0.30    USB_D        Reserved   Reserved
    unsigned        : 2; //|Reserved Reserved      Reserved   Reserved
    unsigned p1_00  : 2; //|P1.00    ENET_TXD0     Reserved   Reserved 0x08 reg2
    unsigned p1_01  : 2; //|P1.01    ENET_TXD1     Reserved   Reserved
    unsigned        : 2; //|Reserved Reserved      Reserved   Reserved
    unsigned        : 2; //|Reserved Reserved      Reserved   Reserved
    unsigned p1_04  : 2; //|P1.4     ENET_TX_EN    Reserved   Reserved 0x09
    unsigned        : 2; //|Reserved Reserved      Reserved   Reserved
    unsigned        : 2; //|                      
    unsigned        : 2; //|                      
    unsigned p1_08  : 2; //|P1.8     ENET_CRS      Reserved   Reserved 0x0A
    unsigned p1_09  : 2; //|P1.9     ENET_RXD0     Reserved   Reserved
    unsigned p1_10  : 2; //|P1.10    ENET_RXD1     Reserved   Reserved
    unsigned        : 2; //|
    unsigned        : 2; //| 0x0B
    unsigned        : 2; //|
    unsigned p1_14  : 2; //|P1.14    ENET_RX_ER    Reserved   Reserved
    unsigned p1_15  : 2; //|P1.15    ENET_REF_CLK  Reserved   Reserved
    unsigned p1_16  : 2; //|P1.16    ENET_MDC      Reserved   Reserved 0x0C reg3
    unsigned p1_17  : 2; //|P1.17    ENET_MDIO     Reserved   Reserved
    unsigned p1_18  : 2; //|P1.18    USB_UP_LED    PWM1.1     CAP1.0
    unsigned p1_19  : 2; //|P1.19    MCOA0         USB_PPWR   CAP1.1
    unsigned p1_20  : 2; //|P1.20    MCI0          PWM1.2     SCK0 0x0D
    unsigned p1_21  : 2; //|P1.21    MCABORT       PWM1.3     SSEL0
    unsigned p1_22  : 2; //|P1.22    MCOB0         USB_PWRD   MAT1.0
    unsigned p1_23  : 2; //|P1.23    MCI1          PWM1.4     MISO0
    unsigned p1_24  : 2; //|P1.24    MCI2          PWM1.5     MOSI0 0x0E
    unsigned p1_25  : 2; //|P1.25    MCOA1         Reserved   MAT1.1
    unsigned p1_26  : 2; //|P1.26    MCOB1         PWM1.6     CAP0.0
    unsigned p1_27  : 2; //|P1.27    CLKOUT        USB_OVRCR  CAP0.1
    unsigned p1_28  : 2; //|P1.28    MCOA2         PCAP1.0    MAT0.0 0x0F
    unsigned p1_29  : 2; //|P1.29    MCOB2         PCAP1.1    MAT0.1
    unsigned p1_30  : 2; //|P1.30    Reserved      VBUS       AD0.4
    unsigned p1_31  : 2; //|P1.31    Reserved      SCK1       AD0.5         
    unsigned p2_00  : 2; //|P2.00    PWM1.1        TXD1       Reserved 0x10 reg4
    unsigned p2_01  : 2; //|P2.01    PWM1.2        RXD1       Reserved
    unsigned p2_02  : 2; //|P2.02    PWM1.3        CTS1       Reserved [
    unsigned p2_03  : 2; //|P2.03    PWM1.4        DCD1       Reserved        
    unsigned p2_04  : 2; //|P2.04    PWM1.5        DSR1       Reserved 0x11
    unsigned p2_05  : 2; //|P2.05    PWM1.6        DTR1       Reserved
    unsigned p2_06  : 2; //|P2.06    PCAP1.0       RI1        Reserved
    unsigned p2_07  : 2; //|P2.07    RD2           RTS1       Reserved        
    unsigned p2_08  : 2; //|P2.08    TD2           TXD2       ENET_MDC 0x12
    unsigned p2_09  : 2; //|P2.09    USB_CONNECT   RXD2       ENET_MDIO
    unsigned p2_10  : 2; //|P2.10    EINT0         NMI        Reserved
    unsigned p2_11  : 2; //|P2.11    EINT1         Reserved   I2STX_CLK        
    unsigned p2_12  : 2; //|P2.12    EINT2         Reserved   I2STX_WS 0x13
    unsigned p2_13  : 2; //|P2.13    EINT3         Reserved   I2STX_SDA
    unsigned        : 2; //|Reserved Reserved      Reserved   Reserved                    
    unsigned        : 2; //| 
    unsigned        :32; //| 0x14 reg5
    unsigned        :32; //| 0x18 reg6
    unsigned        : 2; //| 0x1C reg7
    unsigned        : 2; //| 
    unsigned        : 2; //|        
    unsigned        : 2; //| 
    unsigned        : 2; //| 0x1D       
    unsigned        : 2; //|        
    unsigned        : 2; //|        
    unsigned        : 2; //|        
    unsigned        : 2; //|Reserved Reserved      Reserved   Reserved               0x1E
    unsigned p3_25  : 2; //|P3.25    Reserved      MAT0.0     PWM1.2 
    unsigned p3_26  : 2; //|P3.26    STCLK         MAT0.1     PWM1.3
    unsigned        : 2; //|        
    unsigned        : 2; //| 0x1F
    unsigned        : 2; //|        
    unsigned        : 2; //| 
    unsigned        : 2; //|        
    unsigned        :32; //| 0x20 reg8
    unsigned        :18; //| 0x24 reg9
    unsigned p4_28  : 2; //|P4.28    RX_MCLK       MAT2.0 TXD3
    unsigned p4_29  : 2; //|P4.29    TX_MCLK       MAT2.1 RXD3
    unsigned        :10; //|
    unsigned        : 2; //| 0x28 reg10
    unsigned trace  : 1; //|
    unsigned        :28; //|
}PinConfig;                

typedef struct{         
    unsigned p0_00  : 1;
    unsigned p0_01  : 1;
    unsigned p0_02  : 1;
    unsigned p0_03  : 1;
    unsigned p0_04  : 1;
    unsigned p0_05  : 1;
    unsigned p0_06  : 1;
    unsigned p0_07  : 1;
    unsigned p0_08  : 1;
    unsigned p0_09  : 1;
    unsigned p0_10  : 1;
    unsigned p0_11  : 1;
    unsigned        : 1;
    unsigned        : 1;
    unsigned        : 1;
    unsigned p0_15  : 1;
    unsigned p0_16  : 1;
    unsigned p0_17  : 1;
    unsigned p0_18  : 1;
    unsigned p0_19  : 1;
    unsigned p0_20  : 1;
    unsigned p0_21  : 1;
    unsigned p0_22  : 1;
    unsigned p0_23  : 1;
    unsigned p0_24  : 1;
    unsigned p0_25  : 1;
    unsigned p0_26  : 1;
    unsigned        : 1;
    unsigned        : 1;
    unsigned p0_29  : 1;
    unsigned p0_30  : 1;
    unsigned        : 1;
    unsigned p1_00  : 1;
    unsigned p1_01  : 1;
    unsigned        : 1;
    unsigned        : 1;
    unsigned p1_04  : 1;
    unsigned        : 1;
    unsigned        : 1;
    unsigned        : 1;
    unsigned p1_08  : 1;
    unsigned p1_09  : 1;
    unsigned p1_10  : 1;
    unsigned        : 1;
    unsigned        : 1;
    unsigned        : 1;
    unsigned p1_14  : 1;
    unsigned p1_15  : 1;
    unsigned p1_16  : 1;
    unsigned p1_17  : 1;
    unsigned p1_18  : 1;
    unsigned p1_19  : 1;
    unsigned p1_20  : 1;
    unsigned p1_21  : 1;
    unsigned p1_22  : 1;
    unsigned p1_23  : 1;
    unsigned p1_24  : 1;
    unsigned p1_25  : 1;
    unsigned p1_26  : 1;
    unsigned p1_27  : 1;
    unsigned p1_28  : 1;
    unsigned p1_29  : 1;
    unsigned p1_30  : 1;
    unsigned p1_31  : 1;
    unsigned p2_00  : 1;
    unsigned p2_01  : 1;
    unsigned p2_02  : 1;
    unsigned p2_03  : 1;
    unsigned p2_04  : 1;
    unsigned p2_05  : 1;
    unsigned p2_06  : 1;
    unsigned p2_07  : 1;
    unsigned p2_08  : 1;
    unsigned p2_09  : 1;
    unsigned p2_10  : 1;
    unsigned p2_11  : 1;
    unsigned p2_12  : 1;
    unsigned p2_13  : 1;
    unsigned        : 1;
    unsigned        : 1;
    unsigned        :16;
    unsigned        :16;
    unsigned        : 1;
    unsigned        : 1;
    unsigned        : 1;
    unsigned        : 1;
    unsigned        : 1;
    unsigned        : 1;
    unsigned        : 1;
    unsigned        : 1;
    unsigned        : 1;
    unsigned p3_25  : 1;
    unsigned p3_26  : 1;
    unsigned        : 1;
    unsigned        : 1;
    unsigned        : 1;
    unsigned        : 1;
    unsigned        : 1;
    unsigned        :16;
    unsigned        : 8;
    unsigned p4_28  : 1;
    unsigned p4_29  : 1;
}PinModeOpenDrain; 

#define PIN_MODE_PULLUP   0
#define PIN_MODE_REPEATER 1 
#define PIN_MODE_FLOAT    2 
#define PIN_MODE_PULLDOWN 3 

#define PIN_FUNC     (*(volatile PinConfig *)(0x4002C000))
#define PIN_MODE     (*(volatile PinConfig *)(0x4002C040))
#define PIN_DRAIN    (*(volatile PinModeOpenDrain *)(0x4002C068))


//todo: break this out or move to i2c driver configurations.
#define PINI2CCONFIG (*(volatile uint32_t *)(0x4002C07C))


#endif // __HWDEF_PINMX_H




