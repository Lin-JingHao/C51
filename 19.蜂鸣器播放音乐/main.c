#include <REGX52.H>
#include "Timer_0.h"
#include "Delay.h"

sbit Buzzer=P2^5;

unsigned int FreqTable[]={
	63628,63731,63835,63928,64021,64103,64185,64260,64331,64400,64463,64528,
	64580,64633,64684,64732,64777,64820,64860,64898,64934,64968,65000,65030,
	65058,65085,65110,65134,65157,65178,65198,65217,65235,65252,65268,65283
	};//音符频率

unsigned char Music[]={12,12,19,19,21,21,19,17,17,16,16,14,14,12};
	
	unsigned char FreqSelect,MusicSelect;
	
void main()
{
	Timer0Init();	
	while(1)
	{
		MusicSelect++;
		FreqSelect=Music[MusicSelect];		
		Delay(1000);
		TR0=0;
		Delay(5);
		TR0=1;
	}
}

void Timer0_Rontine() interrupt 1
{ 	
	TL0 =FreqTable[FreqSelect]%256;		
	TH0 =FreqTable[FreqSelect]/256;	
	Buzzer=!Buzzer;   //1ms 500hz;
	
}
