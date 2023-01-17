#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char keynum;
unsigned int Password,count;

void main()
{
	
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	
	while(1)
	{
		keynum=MatrixKey();
		if(keynum)
		{
			if(keynum<=10)
			{
				if(count<4)
				{
					Password*=10;
					Password+=keynum%10;
					count++;					
				}
				LCD_ShowNum(2,1,Password,4);			
			}
			if(keynum==11)
			{
				if(Password==2003)
				{
					LCD_ShowString(1,12,"OK  ");
					Password=0;
					count=0;
					LCD_ShowNum(2,1,Password,4);
				}
				else
				{
					LCD_ShowString(1,12,"erro");
					Password=0;
					count=0;
					LCD_ShowNum(2,1,Password,4);				
				}
			}
			if(keynum==12)
			{
				Password=0;
				count=0;
				LCD_ShowNum(2,1,Password,4);
			}
			
		}	
		
		
	}
}