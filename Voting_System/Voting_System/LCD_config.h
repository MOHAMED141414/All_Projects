/********************************************************/
/************ Name: Mohaemd Esam ************************/
/************ Date:9/8/2024 *****************************/
/************ SWC: LCD  *********************************/
/************ version: 1.0 ******************************/
/********************************************************/


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_DATA_PORT      DIO_PORTA
/* RS,RW,EN */
#define LCD_CONTROL_PORT   DIO_PORTB

#define LCD_RS             DIO_PIN0
#define LCD_RW             DIO_PIN1
#define LCD_EN             DIO_PIN2

#define Function_Set     0x38  //0b00111000    
#define DIS_ON_Curr_OFF  0x0C  //0b00001111   
#define Clear_Lcd        0x01  //0b00000001
#define Entry_Mode       0x06  //0b00000110

#define LCD_ROW1         1
#define LCD_ROW2         2

#endif /* LCD_CONFIG_H_ */