/********************************************************/
/************ Name: Mohaemd Esam ************************/
/************ SWC: I2C  *********************************/
/************ Layer: MCAL********************************/
/********************************************************/
#include "std_types.h"
#include "Bit_math.h"
#include "IIC_interface.h"
#include "IIC_config.h"
#include "IIC_private.h"

void TWI_init(void) {
	TWBR = 0x02;
	TWSR = 0x00;
	TWCR = (1 << TWEN);
	TWAR = 0b00000010;

}

void TWI_start(void) {
	TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWSTA);
	while (GET_BIT(TWCR, TWINT)==0);

}

void TWI_stop(void) {
	TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWSTO);
}

void TWI_write(u8 data) {
	TWDR = data;
	TWCR = (1 << TWEN) | (1 << TWINT);
	while (GET_BIT(TWCR, TWINT) == 0);
}

u8 TWI_readWithACK(void) {
	TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWEA);
	while (GET_BIT(TWCR, TWINT)==0);
	return TWDR;

}

u8 TWI_readWithNACK(void) {

	TWCR = (1 << TWEN) | (1 << TWINT);
	while (GET_BIT(TWCR, TWINT) == 0);
	return TWDR;

}

u8 TWI_getStatus(void){
	u8 status=(TWSR&0xF8);
	return status;
}