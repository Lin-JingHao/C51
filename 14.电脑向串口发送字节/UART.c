#include <REGX52.H>

void UART_Init()        //4800bps@11.0592MHz
{
	PCON |= 0x80;		//使能波特率倍速位SMOD
	SCON = 0x50;		//8位数据,可变波特率
	TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xF4;		//设定定时初值
	TH1 = 0xF4;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	EA=1;
	ES=1;
}


void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;        //发送字节
	while(TI==0);
	TI=0;
}



/*串口中断函数模板
void UART_Routine() interrupt 4
{
	if(RI=1)
	{
		
		RI=0;
	}
	
}
*/
