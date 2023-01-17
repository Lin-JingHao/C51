#include <REGX52.H>
void Delay(unsigned int xms)	//@12.000MHz
{
	while(xms--)
	{
		unsigned char i, j;

	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
	}
	
}

void main()
{
	unsigned char ena=0;
	while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			ena++;
			P2=~ena;
		}
		
		
	}
}