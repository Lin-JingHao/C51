#include <REGX52.H>
#include "Delay.h"

sbit SER=P3^4;  //SER
sbit SCK=P3^6;  //SERCLK
sbit RCK=P3^5;  //RCLK

void _74h595_Init(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SER=Byte&(0x80>>i);
		SCK=1;
		SCK=0;
	}
	
		RCK=1;
		RCK=0;
}

void MatrixLED_ShowColumn(unsigned char X,Y)  //X表示行，Y表示列
{
	 _74h595_Init(X);  //当给 1 时选中
	P0=~(0x80>>Y);  //当给 0 时选中，加了取反符号~，向右移时能补零
	Delay(1);
	P0=0xFF;
}
void main()
{
	SCK=0;
	RCK=0;
	
	while(1)
	{
		MatrixLED_ShowColumn(0x3c,0);
		MatrixLED_ShowColumn(0x42,1);
		MatrixLED_ShowColumn(0xa5,2);
		MatrixLED_ShowColumn(0x89,3);
		MatrixLED_ShowColumn(0x89,4);
		MatrixLED_ShowColumn(0xa5,5);
		MatrixLED_ShowColumn(0x42,6);
		MatrixLED_ShowColumn(0x3c,7);
	}
}