/********************************************************/
/************ Name: Mohaemd Esam ************************/
/************ SWC: LED     ******************************/
/************ Layer: HAL ********************************/
/********************************************************/


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define LED_PIN0        DIO_PIN0
#define LED_PIN1        DIO_PIN1
#define LED_PIN2        DIO_PIN2
#define LED_PIN3        DIO_PIN3
#define LED_PIN4        DIO_PIN4
#define LED_PIN5        DIO_PIN5
#define LED_PIN6        DIO_PIN6
#define LED_PIN7        DIO_PIN7

#define LED_PORTA       DIO_PORTA
#define LED_PORTB       DIO_PORTB
#define LED_PORTC       DIO_PORTC
#define LED_PORTD       DIO_PORTD



void LED_voidInit(u8 Copy_u8PORT,u8 Copy_u8PIN);
void LED_voidHigh(u8 Copy_u8PORT,u8 Copy_u8PIN);
void LED_voidLow(u8 Copy_u8PORT,u8 Copy_u8PIN);
void LED_voidToggle(u8 Copy_u8PORT,u8 Copy_u8PIN);


#endif /* LED_INTERFACE_H_ */