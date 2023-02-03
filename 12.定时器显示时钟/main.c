#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "TIMER0.H"

unsigned char sec=15,min=11,hour=17;
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
	TL0 = 0x66;		
	TH0 = 0xFC;	
	T0count++;
	if(T0count>=1000)
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