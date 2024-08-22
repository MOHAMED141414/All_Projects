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



int main(void)
{
    App();
    while (1) 
    {
    }
}

