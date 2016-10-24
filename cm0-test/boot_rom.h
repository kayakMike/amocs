typedef struct {
    const uint32_t reserved0;        /*!< Reserved */
    const uint32_t reserved1;        /*!< Reserved */
    const uint32_t reserved2;        /*!< Reserved */
    const PWRD_API_T *pPWRD;         /*!< Power API function table base address */
    const ROM_DIV_API_T *divApiBase; /*!< Divider API function table base address */
    const I2CD_API_T *pI2CD;         /*!< I2C driver routines functions table */
    const uint32_t reserved5;        /*!< Reserved */
    const SPID_API_T *pSPID;         /*!< SPI driver API function table base address */
    const ADCD_API_T *pADCD;         /*!< ADC driver API function table base address */
    const UARTD_API_T *pUARTD;       /*!< USART driver API function table base address */
} LPC_ROM_API_T;
#define ROM_DRIVER_BASE (0x1FFF1FF8UL)
