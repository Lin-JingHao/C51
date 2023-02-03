#ifndef _MatrixLED_h_
#define _MatrixLED_h_

void _74h595_Init(unsigned char Byte);
void MatrixLED_ShowColumn(unsigned char X,Y);  //X表示行，Y表示列
void MatrixLED_Init();


#endif
