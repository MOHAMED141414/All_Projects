/********************************************************/
/************ Name: Mohaemd Esam ************************/
/************ SWC: LCD     ******************************/
/************ Layer: HAL ********************************/
/********************************************************/

#define F_CPU 8000000UL
#include <util/delay.h>
#include "std_types.h"
#include "Bit_math.h"
#include "DIO_interface.h"
#include "DIO_priv.h"
#include "DIO_config.h"
#include "LCD_interface.h"
#include "LCD_config.h"

void LCD_voidInit(void)
{
	_delay_ms(50); 
	DIO_u8SetPortDirection(LCD_DATA_PORT,DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT,LCD_RS,DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT,LCD_RW,DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT,LCD_EN,DIO_OUTPUT);
	LCD_voidSendCommand(Function_Set); 
	_delay_ms(1);
	LCD_voidSendCommand(DIS_ON_Curr_OFF);     
	_delay_ms(1);
	LCD_voidClearScreen();
	LCD_voidSendCommand(Entry_Mode);  
	_delay_ms(1);
	 
}
void LCD_voidSendCommand(u8 Copy_u8Command)
{
	DIO_u8SetPortValue(LCD_DATA_PORT,Copy_u8Command);
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_RS,DIO_LOW);
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_RW,DIO_LOW);
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_EN,DIO_HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_EN,DIO_LOW);	
	_delay_ms(1);
}
void LCD_voidSenddata(u8 Copy_u8data)
{
	DIO_u8SetPortValue(LCD_DATA_PORT,Copy_u8data);
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_RS,DIO_HIGH);
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_RW,DIO_LOW);
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_EN,DIO_HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(LCD_CONTROL_PORT,LCD_EN,DIO_LOW);
	_delay_ms(1);
}
void LCD_voidSendString(const u8 *Copy_u8Data)
{
	u8 LOC_u8counter = 0 ;
	while(Copy_u8Data[LOC_u8counter] != '\0')
	{
		LCD_voidSenddata(Copy_u8Data[LOC_u8counter]);
		LOC_u8counter++;
	}
}
void LCD_voidClearScreen(void)
{
	LCD_voidSendCommand(Clear_Lcd);
	_delay_ms(10); 
}
void LCD_voidSendNumber(u64 Copy_u64Number)
{
	u64 LOC_u64Reversed = 1 ;

	if( Copy_u64Number == 0 ){
		 LCD_voidSenddata('0');
		 
		  }

	else{

		while( Copy_u64Number != 0 ){

			LOC_u64Reversed = ( LOC_u64Reversed * 10 ) + ( Copy_u64Number % 10 ); // 10 +1 = 11
			Copy_u64Number /= 10 ;  

		}
		while( LOC_u64Reversed != 1 ){

			LCD_voidSenddata( ( LOC_u64Reversed % 10 ) + 48 );
			LOC_u64Reversed /= 10 ;

		}

	}

}
void LCD_voidSetPosition(u8 Copy_u8ROW,u8 Copy_u8COL)
{
	if (Copy_u8COL <= 39)
	{
		switch(Copy_u8ROW)
		{
			case LCD_ROW1:LCD_voidSendCommand(0x80 + (Copy_u8COL%16) );break;
			case LCD_ROW2:LCD_voidSendCommand(0xc0 + (Copy_u8COL%16) );break;
			default:                                              break;
		}
	}
	else{}
}