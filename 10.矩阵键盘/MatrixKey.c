#include <REGX52.H>
#include "Delay.h"
//¾ØÕó¼üÅÌ°´¼ü
unsigned char MatrixKey()
{
	unsigned char Keynumber=0;
	P1=0xff;
	P1_3=0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);Keynumber=1;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);Keynumber=5;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);Keynumber=9;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);Keynumber=13;}
	
	P1=0xff;
	P1_2=0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);Keynumber=2;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);Keynumber=6;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);Keynumber=10;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);Keynumber=14;}
	
	P1=0xff;
	P1_1=0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);Keynumber=3;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);Keynumber=7;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);Keynumber=11;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);Keynumber=15;}
	
	P1=0xff;
	P1_0=0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);Keynumber=4;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);Keynumber=8;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);Keynumber=12;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);Keynumber=16;}
	
	return Keynumber;
}
