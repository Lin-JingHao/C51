#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "TIMER0.H"

unsigned char sec=56,min=59,hour=23;
void main()
{
	LCD_Init();
	Timer0Init();
	LCD_ShowString(1,1,"Clock:");	
	while(1)
	{
		LCD_ShowNum(2,1,hour,2);
		LCD_ShowString(2,3,":");	
		LCD_ShowNum(2,4,min,2);
		LCD_ShowString(2,6,":");
		LCD_ShowNum(2,7,sec,2);
		
	}
}

void Timer0_Rontine() interrupt 1
{ 
	static unsigned int T0count;
	TH0=65535/256;
	TL0=65535%256;
	T0count++;
	if(T0count>=10000)
	{
		T0count=0;
		sec++;
		if(sec>=60)
		{
			sec=0;
			min++;
			if(min>=60)
			{
				min=0;				
				hour++;
				if(hour>=24)
					hour=0;
			}
		}
		
	}
}