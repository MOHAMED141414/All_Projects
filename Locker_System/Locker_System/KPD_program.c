/********************************************************/
/************ Name: Mohaemd Esam ************************/
/************ SWC: KEYPAD  ******************************/
/************ Layer: HAL ********************************/
/********************************************************/
#define F_CPU 8000000UL
#include <util/delay.h>

#include "std_types.h"
#include "Bit_math.h"

#include "DIO_interface.h"
#include "DIO_priv.h"
#include "DIO_config.h"
#include "KPD_interface.h"
#include "KPD_config.h"

void KPD_voidInit(void)
{
	DIO_u8SetPinDirection( KPD_PORT , KPD_R0 , DIO_INPUT );
	DIO_u8SetPinDirection( KPD_PORT , KPD_R1 , DIO_INPUT );
	DIO_u8SetPinDirection( KPD_PORT , KPD_R2 , DIO_INPUT );
	DIO_u8SetPinDirection( KPD_PORT , KPD_R3 , DIO_INPUT );

	DIO_u8SetPinValue( KPD_PORT , KPD_R0 , DIO_HIGH );
	DIO_u8SetPinValue( KPD_PORT , KPD_R1 , DIO_HIGH );
	DIO_u8SetPinValue( KPD_PORT , KPD_R2 , DIO_HIGH );
	DIO_u8SetPinValue( KPD_PORT , KPD_R3 , DIO_HIGH );
	
	DIO_u8SetPinDirection( KPD_PORT , KPD_C0 , DIO_OUTPUT );
	DIO_u8SetPinDirection( KPD_PORT , KPD_C1 , DIO_OUTPUT );
	DIO_u8SetPinDirection( KPD_PORT , KPD_C2 , DIO_OUTPUT );
	DIO_u8SetPinDirection( KPD_PORT , KPD_C3 , DIO_OUTPUT );

	DIO_u8SetPinValue    ( KPD_PORT , KPD_C0 , DIO_HIGH );
	DIO_u8SetPinValue    ( KPD_PORT , KPD_C1 , DIO_HIGH );
	DIO_u8SetPinValue    ( KPD_PORT , KPD_C2 , DIO_HIGH );
	DIO_u8SetPinValue    ( KPD_PORT , KPD_C3 , DIO_HIGH );
}
   u8 KPD_u8GetPressed(void)
{
	u8 LOC_u8ReturnData = NotPressed;
	u8 LOC_u8GetPressed;
	u8 LOC_u8Row, LOC_u8Col;

	for(LOC_u8Col = 0 + KPD_COL_INIT; LOC_u8Col < KPD_COL_END + 1; LOC_u8Col++)
	{
		DIO_u8SetPinValue(KPD_PORT, LOC_u8Col, DIO_LOW);

		for(LOC_u8Row = 0 + KPD_ROW_INIT; LOC_u8Row < KPD_ROW_END + 1; LOC_u8Row++)
		{
			DIO_u8GetPinValue(KPD_PORT, LOC_u8Row, &LOC_u8GetPressed);

			if(LOC_u8GetPressed == DIO_LOW)
			{
				_delay_ms(10);  // Reduced delay for bouncing

				DIO_u8GetPinValue(KPD_PORT, LOC_u8Row, &LOC_u8GetPressed);

				if(LOC_u8GetPressed == DIO_LOW)
				{
					LOC_u8ReturnData = KPD_u8Buttons[LOC_u8Row - KPD_ROW_INIT][LOC_u8Col - KPD_COL_INIT];
					while(LOC_u8GetPressed == DIO_LOW) // Stay here if button is still pressed
					{
						DIO_u8GetPinValue(KPD_PORT, LOC_u8Row, &LOC_u8GetPressed);
					}
					break;
				}
			}
		}

		DIO_u8SetPinValue(KPD_PORT, LOC_u8Col, DIO_HIGH);

		if (LOC_u8ReturnData != NotPressed)
		{
			break;
		}
	}

	return LOC_u8ReturnData;
}

u8 KPD_u8Buttons[4][4]={ {'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'C','0','=','+'} };
