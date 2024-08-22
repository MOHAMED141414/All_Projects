/********************************************************/
/************ Name: Mohaemd Esam ************************/
/************ SWC: EEPROM  ******************************/
/************ Layer: HAL ********************************/
/********************************************************/
#define F_CPU 8000000UL
#include <util/delay.h> 
#include "std_types.h"
#include "Bit_math.h"

#include "IIC_interface.h"
#include "IIC_config.h"
#include "IIC_private.h"
#include "EEPROM_interface.h"
#include "EEPROM_config.h"
#include "EEPROM_private.h"


void EEPROM_init(void)
{
	/* just initialize the I2C(TWI) module inside the MC */
	TWI_init();
}

u8 EEPROM_writeByte(u16 u16addr, u8 u8data)
{
	/* Send the Start Bit */
    TWI_start();
    if (TWI_getStatus() != TW_START)
        return ERROR;

    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=0 (write) */
    TWI_write((u8)(0xA0 | ((u16addr & 0x0700)>>7)));
    if (TWI_getStatus() != TW_MT_SLA_W_ACK)
        return ERROR;

    /* Send the required memory location address */
    TWI_write((u8)(u16addr));
    if (TWI_getStatus() != TW_MT_DATA_ACK)
        return ERROR;

    /* write byte to eeprom */
    TWI_write(u8data);
    if (TWI_getStatus() != TW_MT_DATA_ACK)
        return ERROR;

    /* Send the Stop Bit */
    TWI_stop();
	
    return SUCCESS;
}

u8 EEPROM_readByte(u16 u16addr, u8 *u8data)
{
	/* Send the Start Bit */
    TWI_start();
    if (TWI_getStatus() != TW_START)
        return ERROR;
		
    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=0 (write) */
    TWI_write((u8)((0xA0) | ((u16addr & 0x0700)>>7)));
    if (TWI_getStatus() != TW_MT_SLA_W_ACK)
        return ERROR;
		
    /* Send the required memory location address */
    TWI_write((u8)(u16addr));
    if (TWI_getStatus() != TW_MT_DATA_ACK)
        return ERROR;
		
    /* Send the Repeated Start Bit */
    TWI_start();
    if (TWI_getStatus() != TW_REP_START)
        return ERROR;
		
    /* Send the device address, we need to get A8 A9 A10 address bits from the
     * memory location address and R/W=1 (Read) */
    TWI_write((u8)((0xA0) | ((u16addr & 0x0700)>>7) | 1));
    if (TWI_getStatus() != TW_MT_SLA_R_ACK)
        return ERROR;

    /* Read Byte from Memory without send ACK */
    *u8data = TWI_readWithNACK();
    if (TWI_getStatus() != TW_MR_DATA_NACK)
        return ERROR;

    /* Send the Stop Bit */
    TWI_stop();
    return SUCCESS;
}
