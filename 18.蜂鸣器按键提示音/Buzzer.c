#include <REGX52.H>         //蜂鸣器
#include "Delay.h"
#include <INTRINS.H>  
sbit Buzzer=P2^5;
//蜂鸣器私有延时函数，延时500us
void Buzzer_Delay500us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 227;
	while (--i);
}
//蜂鸣器发声
//ms 发声时长
//
void Buzzer_Time(unsigned int xms)
{
	unsigned int i;			
	for(i=0;i<xms*2;i++)
	{
		Buzzer=!Buzzer;
		Buzzer_Delay500us();
	}
}
