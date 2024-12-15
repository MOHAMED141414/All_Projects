/********************************************************/
/************ Name: Mohaemd Esam ************************/
/************ Date:9/8/2024 *****************************/
/************ SWC: LCD  *********************************/
/************ version: 1.0 ******************************/
/********************************************************/
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidInit(void);
void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSenddata(u8 Copy_u8data);
void LCD_voidSendString(const u8 *Copy_u8Data);
void LCD_voidClearScreen(void);
void LCD_voidSendNumber(u64 Copy_u64Number);
void LCD_voidSetPosition(u8 Copy_u8ROW,u8 Copy_u8COL);


#endif /* LCD_INTERFACE_H_ */