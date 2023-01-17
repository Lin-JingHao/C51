#include <REGX52.H>

void Timer0Init(void)		//@11.0592MHz
{
	TMOD &= 0xF0;		
	TMOD |= 0x01;	
	TL0 = 0x66;		
	TH0 = 0xFC;		
	TF0 = 0;		
	TR0 = 1;		
	ET0=1;
	EA=1;
	PT0=0;
	
}


/*
void Timer0_Rontine() interrupt 1
{ 
	static unsigned int T0count;
	TH0=65535/256;
	TL0=65535%256;
	T0count++;
	if(T0count>=10000)
	{
		T0count=0;
	
	}
	
	
}

*/