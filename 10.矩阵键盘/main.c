#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char keynum;

void main()
{
	LCD_Init();
	
	while(1)
	{
		keynum=MatrixKey();
		if(keynum)
		{
			LCD_ShowNum(1,2,keynum,3);
		}	
	}
}