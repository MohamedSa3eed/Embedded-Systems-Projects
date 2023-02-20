#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

void LCD_Init(void);
void LCD_WriteCommand(u8 Command);
void LCD_WriteData(u8 Data);
void LCD_WriteDigits(s32 Number);
void LCD_WriteString(char *String);
void LCD_GoToXY(u8 X_Pos,u8 Y_Pos);
void LCD_WriteSpecial(u8 * Special_Character,u8 CGRAM_Index,u8 X_Pos ,u8 Y_Pos );

 //commands to write in LCD 

#define dispaly_on              0x0f
#define dispaly_off             0x08
#define return_to_0x00_in_DDRAM 0x02
#define clear                   0x01
#define entry_mode              0x06
#define entry_mode_shifting     0x07
#define entry_mode_reverse      0x04
#define entry_mode_rev_shifting 0x05
#endif
