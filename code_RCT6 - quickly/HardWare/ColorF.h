#ifndef __COLORF_H
#define __COLORF_H

#include "stm32f10x.h"

void ColorF_Init(void);
void ColorF_start(void);
void ColorF_GetGreen(void);
void ColorF_GetRed(void);
void ColorF_GetBlue(void);

void ColorF_Out_Freq_100(void);
void ColorF_Out_Freq_20(void);
void ColorF_Out_Freq_2(void);
void ColorF_Out_Freq_0(void);

#endif

/*API接口说明*/
/* 
	//API接口说明
    调用Buzzer函数，输入值buz为1是蜂鸣器响，其他则不响
	//接线说明
	I/O 接 A12
*/

