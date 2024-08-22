/********************************************************/
/************ Name: Mohaemd Esam ************************/
/************ SWC: EEPROM  ******************************/
/************ Layer: HAL ********************************/
/********************************************************/ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

#define ERROR 0
#define SUCCESS 1

void EEPROM_init(void);
u8 EEPROM_writeByte(u16 u16addr,u8 u8data);
u8 EEPROM_readByte(u16 u16addr,u8 *u8data);



#endif /* EEPROM_INTERFACE_H_ */