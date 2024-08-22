/********************************************************/
/************ Name: Mohaemd Esam ************************/
/************ SWC: LED     ******************************/
/************ Layer: HAL ********************************/
/********************************************************/
#include "std_types.h"
#include "Bit_math.h"

 #include "DIO_interface.h"
 #include "DIO_priv.h"
 #include "DIO_config.h"
 #include "LED_interface.h"
 


void LED_voidInit(u8 Copy_u8PORT,u8 Copy_u8PIN)
{
	DIO_u8SetPinDirection(Copy_u8PORT,Copy_u8PIN,DIO_OUTPUT);
}
void LED_voidHigh(u8 Copy_u8PORT,u8 Copy_u8PIN)
{
	DIO_u8SetPinValue(Copy_u8PORT,Copy_u8PIN,DIO_HIGH);
}
void LED_voidLow(u8 Copy_u8PORT,u8 Copy_u8PIN)
{
	DIO_u8SetPinValue(Copy_u8PORT,Copy_u8PIN,DIO_LOW);
}
void LED_voidToggle(u8 Copy_u8PORT,u8 Copy_u8PIN)
{
	DIO_u8TogglePinValue(Copy_u8PORT,Copy_u8PIN);
}