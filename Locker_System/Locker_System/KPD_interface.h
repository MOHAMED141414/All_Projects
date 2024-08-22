/********************************************************/
/************ Name: Mohaemd Esam ************************/
/************ SWC: KEYPAD  ******************************/
/************ Layer: HAL ********************************/
/********************************************************/


#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

void KPD_voidInit(void);
u8   KPD_u8GetPressed( void );
u8 KPD_u8Buttons[4][4];


#endif /* KPD_INTERFACE_H_ */