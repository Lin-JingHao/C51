#include <REGX52.H>
#include "Delay.h"
#include "keynumber.h"
#include "number.h"
#include "Buzzer.h"

sbit Buzzer=P2^5;

unsigned char key;

void main()
{	
	number(1,0);
	while(1)
	{
		key=keynumber();		
		if(key)
		{		
			Buzzer_Time(100);
			number(1,key);
		}
		
	}
}