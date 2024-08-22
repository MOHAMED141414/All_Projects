/********************************************************/
/************ Name: Mohaemd Esam ************************/
/************ SWC: DIO  *********************************/
/************ Layer: MCAL *******************************/
/********************************************************/

#include "std_types.h"
#include "Bit_math.h"

#include "DIO_interface.h"
#include "DIO_priv.h"
#include "DIO_config.h"

u8 DIO_u8SetPinDirection(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8Direction)
{
	u8 Local_u8Result=DIO_OK;
	
	if((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN<=DIO_PIN7))
	{
		if(Copy_u8Direction == DIO_OUTPUT)
		{
			switch(Copy_u8PORT)
			{
				case DIO_PORTA:SET_BIT(DDRA,Copy_u8PIN);break;
				case DIO_PORTB:SET_BIT(DDRB,Copy_u8PIN);break;
				case DIO_PORTC:SET_BIT(DDRC,Copy_u8PIN);break;
				case DIO_PORTD:SET_BIT(DDRD,Copy_u8PIN);break;
			}
		}
		else if(Copy_u8Direction == DIO_INPUT)
		{
			switch(Copy_u8PORT)
			{
				case DIO_PORTA:CLEAR_BIT(DDRA,Copy_u8PIN);break;
				case DIO_PORTB:CLEAR_BIT(DDRB,Copy_u8PIN);break;
				case DIO_PORTC:CLEAR_BIT(DDRC,Copy_u8PIN);break;
				case DIO_PORTD:CLEAR_BIT(DDRD,Copy_u8PIN);break;
			}
		}
		else
		{
			Local_u8Result=DIO_NOK;
		}
		
	}
	else
	{
		Local_u8Result=DIO_NOK;
	}
	return Local_u8Result;
}
u8 DIO_u8SetPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8Value)
{
	u8 Local_u8Result=DIO_OK;
	if((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN<=DIO_PIN7))
	{
		if(Copy_u8Value == DIO_HIGH)
		{
			switch(Copy_u8PORT)
			{
				case DIO_PORTA:SET_BIT(PORTA,Copy_u8PIN);break;
				case DIO_PORTB:SET_BIT(PORTB,Copy_u8PIN);break;
				case DIO_PORTC:SET_BIT(PORTC,Copy_u8PIN);break;
				case DIO_PORTD:SET_BIT(PORTD,Copy_u8PIN);break;
			}
		}
		else if(Copy_u8Value == DIO_LOW)
		{
			switch(Copy_u8PORT)
			{
				case DIO_PORTA:CLEAR_BIT(PORTA,Copy_u8PIN);break;
				case DIO_PORTB:CLEAR_BIT(PORTB,Copy_u8PIN);break;
				case DIO_PORTC:CLEAR_BIT(PORTC,Copy_u8PIN);break;
				case DIO_PORTD:CLEAR_BIT(PORTD,Copy_u8PIN);break;
			}
		}
		else
		{
			Local_u8Result=DIO_NOK;
		}
	}
	else
	{
		Local_u8Result=DIO_NOK;
	}
	return Local_u8Result;
	
}
u8 DIO_u8ClearPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN)
{
	u8 Local_u8Result=DIO_OK;
	if((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN<=DIO_PIN7))
	{
		switch(Copy_u8PORT)
		{
			case DIO_PORTA:CLEAR_BIT(PORTA,Copy_u8PIN);break;
			case DIO_PORTB:CLEAR_BIT(PORTB,Copy_u8PIN);break;
			case DIO_PORTC:CLEAR_BIT(PORTC,Copy_u8PIN);break;
			case DIO_PORTD:CLEAR_BIT(PORTD,Copy_u8PIN);break;
		}
	}
	else
	{
		Local_u8Result=DIO_NOK;
	}
	return Local_u8Result;
}
u8 DIO_u8TogglePinValue(u8 Copy_u8PORT,u8 Copy_u8PIN)
{
	u8 Local_u8Result=DIO_OK;
	if((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN<=DIO_PIN7))
	{
		switch(Copy_u8PORT)
		{
			case DIO_PORTA:TOGGLE_BIT(PORTA,Copy_u8PIN);break;
			case DIO_PORTB:TOGGLE_BIT(PORTB,Copy_u8PIN);break;
			case DIO_PORTC:TOGGLE_BIT(PORTC,Copy_u8PIN);break;
			case DIO_PORTD:TOGGLE_BIT(PORTD,Copy_u8PIN);break;
		}
	}
	else
	{
		Local_u8Result=DIO_NOK;
	}
	return Local_u8Result;
}
u8 DIO_u8GetPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 *Copy_PtrData)
{
	u8 Local_u8Result=DIO_OK;
	if((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN<=DIO_PIN7) &&  (Copy_PtrData != NULL) )
	{
		switch(Copy_u8PORT)
		{
			case DIO_PORTA:*Copy_PtrData=GET_BIT(PINA,Copy_u8PIN);break;
			case DIO_PORTB:*Copy_PtrData=GET_BIT(PINB,Copy_u8PIN);break;
			case DIO_PORTC:*Copy_PtrData=GET_BIT(PINC,Copy_u8PIN);break;
			case DIO_PORTD:*Copy_PtrData=GET_BIT(PIND,Copy_u8PIN);break;
		}
	}
	else
	{
		 Local_u8Result=DIO_NOK;
	}
	
	return Local_u8Result;
}
u8 DIO_u8SetPortDirection(u8 Copy_u8PORT,u8 Copy_u8Direction)
{
	u8 Local_u8Result=DIO_OK;
	if(Copy_u8PORT <= DIO_PORTD)
	{
		if(Copy_u8Direction == DIO_OUTPUT)
		{
			switch(Copy_u8PORT)
			{
				case DIO_PORTA:DDRA=0xFF;
				break;
				case DIO_PORTB:DDRB=0xFF;
				break;
				case DIO_PORTC:DDRC=0xFF;
				break;
				case DIO_PORTD:DDRD=0xFF;
				break;
			}
		}
		else if(Copy_u8Direction == DIO_INPUT)
		{
			switch(Copy_u8PORT)
			{
				case DIO_PORTA:DDRA=0x00;
				break;
				case DIO_PORTB:DDRB=0x00;
				break;
				case DIO_PORTC:DDRC=0x00;
				break;
				case DIO_PORTD:DDRD=0x00;
				break;
			}
		}
		else
		{
			Local_u8Result=DIO_NOK;
		}
	}
	else
	{
		Local_u8Result=DIO_NOK;
	}
	return Local_u8Result;
}
u8 DIO_u8SetPortValue(u8 Copy_u8PORT,u8 Copy_u8Value)
{
	u8 Local_u8Result=DIO_OK;
	if ( (Copy_u8PORT <=DIO_PORTD) && ( (Copy_u8Value == DIO_PORT_HIGH) || (Copy_u8Value<=255) || (Copy_u8Value == DIO_PORT_LOW) ) )
	{
		switch(Copy_u8PORT)
		{
			case DIO_PORTA:PORTA=Copy_u8Value;break;
			case DIO_PORTB:PORTB=Copy_u8Value;break;
			case DIO_PORTC:PORTC=Copy_u8Value;break;
			case DIO_PORTD:PORTD=Copy_u8Value;break;
			default:Local_u8Result=DIO_NOK; break;
		}
	}
	else
	{
		Local_u8Result=DIO_NOK;
	}
	return Local_u8Result;
}
u8 DIO_u8ClearPortValue(u8 Copy_u8PORT)
{
	u8 Local_u8Result=DIO_OK; 
	if(Copy_u8PORT <= DIO_PORTD)
	{
		switch(Copy_u8PORT)
		{
			case DIO_PORTA:PORTA=DIO_LOW;
			break;
			case DIO_PORTB:PORTB=DIO_LOW;
			break;
			case DIO_PORTC:PORTC=DIO_LOW;
			break;
			case DIO_PORTD:PORTD=DIO_LOW;
			break;
		}
	}
	else
	{
		Local_u8Result=DIO_NOK;
	}
	return Local_u8Result;
}
u8 DIO_u8GetPortValue(u8 Copy_u8PORT,u8 *Copy_PtrData)
{
	u8 Local_u8Result = DIO_OK;
	if (Copy_u8PORT <= DIO_PORTD &&  (Copy_PtrData != NULL))
	{
		switch(Copy_u8PORT)
		{
			case DIO_PORTA:*Copy_PtrData = PINA;break;
			case DIO_PORTB:*Copy_PtrData = PINB;break;
			case DIO_PORTC:*Copy_PtrData = PINC;break;
			case DIO_PORTD:*Copy_PtrData = PIND;break;
		}
	}
	else
	{
		Local_u8Result=DIO_NOK;
	}
	
	return Local_u8Result;
}


