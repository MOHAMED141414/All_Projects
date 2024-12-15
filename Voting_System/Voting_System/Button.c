#include "std_types.h"
#include "Bit_math.h"
#include "DIO_interface.h"
#include "DIO_priv.h"
#include "DIO_config.h"
#include "button.h"

u8 button_u8read(u8 portname,u8 pinnumber)
{
	unsigned char x;
	x=DIO_u8read(portname,pinnumber);
	return x ;
}
