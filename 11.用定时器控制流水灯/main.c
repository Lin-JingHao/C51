#include <REGX52.H>
#include "Timer0.h" 
#include "keynumber.h"
#include <INTRINS.H>	

unsigned char key ,LEDmode;
void main()
{		
	P2=0xfe;
	Timer0Init();	
	while(1)
	{
		key=keynumber();
		if(key)
		{
			if(key==1)
			{
				LEDmode++;
				if(LEDmode>=2)
					LEDmode=0;
			}						
		}
	}
}


void Timer0_Rontine() interrupt 1
{ 
	static unsigned int T0count;
	TH0=65535/256;
	TL0=65535%256;
	T0count++;
	
	if(T0count>=1000)
	{
	
		T0count=0;
		if(LEDmode==0){P2=_crol_(P2,1);}
		if(LEDmode==1){P2=_cror_(P2,1);}
		
	}	
		
}