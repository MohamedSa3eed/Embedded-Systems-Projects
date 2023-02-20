#include "../LIB/STD_TYPES.h"

#include "../HAL/LCD/LCD_INTERFACE.h"
#include "../HAL/KPD/KPD_INTERFACE.h"

#include </usr/avr/include/avr/delay.h>  // in windows <utility/delay>

#define FIRIST_OPERAND 1
#define SECOND_OPERAND 2

#define NOT_PRESSED    0xff

void restartLCD(void)
{
  LCD_WriteCommand(clear);
  _delay_ms(50);
  LCD_GoToXY(0,0);
}

u8 getKey(void)
{
	u8 KPD_PressedKey;
	while(1)
	{
		do
		{
			KPD_PressedKey = KPD_GetPressedKey();
		}
		while (KPD_PressedKey == NOT_PRESSED);

		break;
	}
	return KPD_PressedKey;
}

void parseInput(s32 operand1 , s32 operand2 , u8 operator , u8 key , u8 op)
{
  while (1)
  {
		key = getKey();
	  if (key >= '0' && key <= '9' && op == FIRIST_OPERAND)
    {
      operand1 *=10 ;
      operand1 += key;
      LCD_WriteData(key + '0');
    }
    else if (key >= '0' && key <= '9' && op == SECOND_OPERAND)
    {
      operand2 *=10 ;
      operand2 +=key;
      LCD_WriteData(key + '0');
    }
    else if (key == '=')
    {
      calculator(operand1, operand2, operator);
      operand1 = 0 ;
      operand2 = 0 ;
    }
    else 
    {
      operator = key ;
      LCD_WriteData(key);
      op = SECOND_OPERAND ;
    }
  }
}

void calculator(s32 operand1 , s32 operand2 , u8 operator)
{
  s32 result = 0;
  switch (operator)
  {
   case '+':  result = operand1 + operand2 ; break;
   case '-':  result = operand1 - operand2 ; break;
   case '*':  result = operand1 * operand2 ; break;
   case '/':  result = operand1 / operand2 ; break;
   case 'c':  restartLCD();
  }
  LCD_WriteDigits(result);
}

int main(int argc, char *argv[])
{
  //initialize the drivers 
  LCD_Init();
  KPD_Init();

  u8 key , operator ;
  s32 operand1=0 , operand2=0 ;
  u8 op  = FIRIST_OPERAND ;
  LCD_WriteString(" 01- calculator ");
  _delay_ms(1500);
  restartLCD();
  parseInput(operand1, operand2, operator, op , key);
  

  return 0;
}
