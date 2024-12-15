#define F_CPU 16000000UL
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
#include "button.h"
#include "App.h"

#define Password_Length   4
u8 pass1[Password_Length]="1234";
u8 pass2[Password_Length];
f32 counter1=0;
f32 counter2=0;
f32 counter3=0;
f32 counter4=0;



void Init_voidSystem(void)
{
	LCD_voidInit();
	KPD_voidInit();
	DIO_u8SetPinDirection(DIO_PORTC, DIO_PIN0, DIO_INPUT); // Push Button A
	DIO_u8SetPinDirection(DIO_PORTC, DIO_PIN1, DIO_INPUT); // Push Button B
	DIO_u8SetPinDirection(DIO_PORTC, DIO_PIN2, DIO_INPUT); // Push Button C
	DIO_u8SetPinDirection(DIO_PORTC, DIO_PIN3, DIO_INPUT); // Push Button D
	DIO_u8SetPinDirection(DIO_PORTC, DIO_PIN4, DIO_INPUT); // Reset Button
	DIO_u8SetPinDirection(DIO_PORTC, DIO_PIN5, DIO_INPUT); // Show Percentages Button
}

u8 compare_passwords(u8* password1, u8* password2) {
	for (u8 i = 0; i < Password_Length; i++) {
		if (password1[i] != password2[i]) {
			return 0;
		}
	}
	return 1;
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
	LCD_voidSendString(" Voting System ");
	_delay_ms(100);
	LCD_voidClearScreen();
	LCD_voidSetPosition(1, 1);
	while(1)
	{
		LCD_voidClearScreen();
		LCD_voidSendString("Enter PIN:");
		LCD_voidSetPosition(2, 4);
		Enter_voidPassword();
		LCD_voidClearScreen();
		
		if (compare_passwords(pass1, pass2))
		{
			LCD_voidSetPosition(1, 0);
			LCD_voidSendString("Correct PIN");
			_delay_ms(50);
			positions();
			while(1)
			{
				u16 total_counter=counter1+counter2+counter3+counter4;
				if (button_u8read(DIO_PORTC,DIO_PIN0)==1)
				{
					counter1++;
					positions();	
				}
				else if (button_u8read(DIO_PORTC,DIO_PIN1)==1)
				{
					counter2++;
					positions();
				}
				else if (button_u8read(DIO_PORTC,DIO_PIN2)==1)
				{
					counter3++;
					positions();
				}
				else if (button_u8read(DIO_PORTC,DIO_PIN3)==1)
				{
					counter4++;
					positions();
				}
				else if (button_u8read(DIO_PORTC,DIO_PIN4)==1)
				{
					counter1=0;
					counter2=0;
					counter3=0;
					counter4=0;
					LCD_voidClearScreen();
					positions();
					
				}
				else if (button_u8read(DIO_PORTC,DIO_PIN5)==1)
				{
					if (total_counter == 0)
					{
						LCD_voidClearScreen();
						LCD_voidSendString("No votes yet!");
						_delay_ms(50);
						LCD_voidClearScreen();
					}
					else
					{
						LCD_voidClearScreen();
						LCD_voidSetPosition(1, 1);
						LCD_voidSendString("A=");
						LCD_voidSetPosition(1,3);
						LCD_voidSendNumber((counter1/total_counter)*100);
						LCD_voidSendString("%");
						LCD_voidSetPosition(1, 10);
						LCD_voidSendString("B=");
						LCD_voidSetPosition(1,12);
						LCD_voidSendNumber((counter2/total_counter)*100);
						LCD_voidSendString("%");
						LCD_voidSetPosition(2, 1);
						LCD_voidSendString("C=");
						LCD_voidSetPosition(2,3);
						LCD_voidSendNumber((counter3/total_counter)*100);
						LCD_voidSendString("%");
						LCD_voidSetPosition(2, 10);
						LCD_voidSendString("D=");
						LCD_voidSetPosition(2,12);
						LCD_voidSendNumber((counter4/total_counter)*100);
						LCD_voidSendString("%");
						
					}
				}
				else
				{
					continue;
				}
			}
			
			
			break;
		}
		else
		{
			Try--;
			LCD_voidSetPosition(1, 1);
			LCD_voidSendString("Wrong PIN");
			LCD_voidSetPosition(2, 0);
			LCD_voidSendString("you have ");
			LCD_voidSendNumber(Try);
			LCD_voidSendString(" tries");
			
			_delay_ms(100);
			
			LCD_voidClearScreen();
			
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



void positions(void)
{
	LCD_voidClearScreen();
	LCD_voidSetPosition(1, 1);
	LCD_voidSendString("A=");
	LCD_voidSetPosition(1,3);
	LCD_voidSendNumber(counter1);
	LCD_voidSetPosition(1, 10);
	LCD_voidSendString("B=");
	LCD_voidSetPosition(1,12);
	LCD_voidSendNumber(counter2);
	LCD_voidSetPosition(2, 1);
	LCD_voidSendString("C=");
	LCD_voidSetPosition(2,3);
	LCD_voidSendNumber(counter3);
	LCD_voidSetPosition(2, 10);
	LCD_voidSendString("D=");
	LCD_voidSetPosition(2,12);
	LCD_voidSendNumber(counter4);
}
