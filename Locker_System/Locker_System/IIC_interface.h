/********************************************************/
/************ Name: Mohaemd Esam ************************/
/************ SWC: I2C  *********************************/
/************ Layer: MCAL********************************/
/********************************************************/


#ifndef IIC_INTERFACE_H_
#define IIC_INTERFACE_H_

void TWI_init(void);
void TWI_start(void);
void TWI_stop(void);
void TWI_write(u8 data);
u8 TWI_readWithACK(void); 
u8 TWI_readWithNACK(void); 
u8 TWI_getStatus(void);



#endif /* IIC_INTERFACE_H_ */