#include <REGX52.H>

void Timer0Init(void)		//@11.0592MHz  1ms
{
	TMOD &= 0xF0;		
	TMOD |= 0x01;	
	TL0 = 0x18;		
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
	TL0 = 0x66;	//设置定时初值	
	TH0 = 0xFC;	//设置定时初值
	T0count++;
	if(T0count>=10000)
	{
		T0count=0;
	
	}
	
	
}

*/