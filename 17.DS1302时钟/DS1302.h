#ifndef _DS1302_H_
#define _DS1302_H_

extern unsigned char DS1302_Time[];

void DS1302_Init(void);
void DS1302_WritieByte(unsigned Command,Data);
unsigned char DS1302_ReadByte(unsigned char Command);
void DS1302_SetTimer(void);
void DS1302_ReadTime(void);


#endif