#include <REGX52.H>
void Delay(unsigned int xms)		//@12.000MHz
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
	unsigned char number=0;
	while(1)
	{   
		if(P3_1==0)
		{
				Delay(20);
				while(P3_1==0);
				Delay(20);			
				if(number>=8)
					number=0;
				P2=~(0x01<<number);
				number++;
		}	
		if(P3_0==0)
		{
				Delay(20);
				while(P3_0==0);
				Delay(20);
			    if(number=0)
					number=7;
				else
					number--;
				P2=~(0x01<<-0number);
		}
		
		
	}
}