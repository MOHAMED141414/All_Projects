/********************************************************/
/************ Name: Mohaemd Esam ************************/
/************ SWC: KEYPAD  ******************************/
/************ Layer: HAL ********************************/
/********************************************************/

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KPD_ROW_INIT    DIO_PIN0
#define KPD_ROW_END     DIO_PIN3

#define KPD_COL_INIT    DIO_PIN4
#define KPD_COL_END     DIO_PIN7

#define	KPD_PORT        DIO_PORTD

#define KPD_R0          DIO_PIN0
#define KPD_R1          DIO_PIN1
#define KPD_R2          DIO_PIN2
#define KPD_R3          DIO_PIN3

#define KPD_C0          DIO_PIN4
#define KPD_C1          DIO_PIN5
#define KPD_C2          DIO_PIN6
#define KPD_C3          DIO_PIN7


							 
#define NotPressed     0xFF

#endif /* KPD_CONFIG_H_ */