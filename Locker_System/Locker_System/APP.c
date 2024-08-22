#define F_CPU 8000000UL
#include <util/delay.h>
#include "std_types.h"
#include "Bit_math.h"

#include "DIO_interface.h"
#include "DIO_priv.h"
#include "DIO_config.h"

#include "LCD_interface.h"
#include "LCD_config.h"

#include "KPD_interface.h"
#include "KPD_config.h"

#include "LED_interface.h"
#include "IIC_interface.h"
#include "IIC_config.h"
#include "IIC_private.h"

#include "EEPROM_interface.h"
#include "EEPROM_config.h"
#include "EEPROM_private.h"

#include "APP_.h"

#define Password_Length   4
u8 pass1[Password_Length];
u8 pass2[Password_Length];

void Init_voidSystem(void)
{
	LCD_voidInit();
	KPD_voidInit();
	LED_voidInit(DIO_PORTB,DIO_PIN4);
	LED_voidInit(DIO_PORTB,DIO_PIN5);
}

u8 compare_passwords(u8* password1, u8* password2) {
	for (u8 i = 0; i < Password_Length; i++) {
		if (password1[i] != password2[i]) {
			return 0;
		}
	}
	return 1;
}

void Set_voidPassword(void)
{
	u8 KeyPressed = 0;
	u8 counter = 0;
	while (counter != Password_Length) {
		KeyPressed = KPD_u8GetPressed();
		if (KeyPressed != NotPressed) {
			LCD_voidSenddata(KeyPressed);
			_delay_ms(5);
			LCD_voidSetPosition(2, 4 + counter);
			LCD_voidSenddata('*');
			pass1[counter] = KeyPressed;
			_delay_ms(1);
			counter++;
		}
	}

}

void Enter_voidPassword(void)
{
	u8 KeyPressed = 0;
	u8 counter = 0;
	while (counter != Password_Length) {
		KeyPressed = KPD_u8GetPressed();
		if (KeyPressed != NotPressed) {
			LCD_voidSenddata(KeyPressed);
			_delay_ms(5);
			LCD_voidSetPosition(2, 4 + counter);
			LCD_voidSenddata('*');
			pass2[counter] = KeyPressed;
			_delay_ms(1);
			counter++;
		}
	}
}

void App(void)
{
	u8 Try=3;
	Init_voidSystem();
	LCD_voidSendString("Welcome to ");
	LCD_voidSetPosition(2, 2);
	LCD_voidSendString(" Locker System ");
	_delay_ms(100);
	LCD_voidClearScreen();
	LCD_voidSetPosition(1, 2);
	LCD_voidSendString("Set Password");
	LCD_voidSetPosition(2, 4);
	Set_voidPassword();

	for (u8 i = 0; i < Password_Length; i++) {
		EEPROM_writeByte(i, pass1[i]) ;
	}

	LCD_voidClearScreen();
	LCD_voidSetPosition(1, 1);
	LCD_voidSendString("Password Saved");
	_delay_ms(50);
	

	LCD_voidClearScreen();
	LCD_voidSetPosition(1, 1);
	while(1)
	{
		LCD_voidClearScreen();
		LCD_voidSendString("Enter Password");
		LCD_voidSetPosition(2, 4);
		Enter_voidPassword();

		LCD_voidClearScreen();
		
		if (compare_passwords(pass1, pass2))
		{
			LCD_voidSetPosition(1, 0);
			LCD_voidSendString("Correct Password");
			LCD_voidSetPosition(2, 2);
			LCD_voidSendString("Locker is open");
			LED_voidHigh(LED_PORTB,LED_PIN5);
			break;
		}
		else
		{
			Try--;
			LCD_voidSetPosition(1, 1);
			LCD_voidSendString("Wrong Password");
			LCD_voidSetPosition(2, 0);
			LCD_voidSendString("you have ");
			LCD_voidSendNumber(Try);
			LCD_voidSendString(" tries");
			LED_voidHigh(LED_PORTB,LED_PIN4);
			_delay_ms(100);
			
			LCD_voidClearScreen();
			LED_voidLow(LED_PORTB,LED_PIN4);
			if (Try == 0)
			{
				Try=3;
				for (u8 i=9;i>0;i-- )
				{
					LCD_voidSetPosition(1, 1);
					LCD_voidSendString("Please wait ");
					LCD_voidSetPosition(2, 2);
					LCD_voidSendNumber(i);
					LCD_voidSendString(" seconds");
					_delay_ms(50);
					
				}
			}
			
			
		}
	}
	
}
