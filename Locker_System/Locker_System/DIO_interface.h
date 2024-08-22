/********************************************************/
/************ Name: Mohaemd Esam ************************/
/************ SWC: DIO  *********************************/
/************ Layer: MCAL *******************************/
/********************************************************/


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_




u8 DIO_u8SetPinDirection(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8Direction);
u8 DIO_u8SetPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8Value);
u8 DIO_u8TogglePinValue(u8 Copy_u8PORT,u8 Copy_u8PIN);
u8 DIO_u8ClearPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN);
u8 DIO_u8GetPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 *Copy_PtrData);
u8 DIO_u8SetPortDirection(u8 Copy_u8PORT,u8 Copy_u8Direction);
u8 DIO_u8SetPortValue(u8 Copy_u8PORT,u8 Copy_u8Value);
u8 DIO_u8ClearPortValue(u8 Copy_u8PORT);
u8 DIO_u8GetPortValue(u8 Copy_u8PORT,u8 *Copy_PtrData);





#endif /* DIO_INTERFACE_H_ */