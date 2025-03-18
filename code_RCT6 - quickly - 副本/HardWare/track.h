#ifndef __TRACK_H
#define __TRACK_H

#include "stm32f10x.h"

#define L3 digtal(1)
#define L2 digtal(2)
#define L1 digtal(3)
#define M  digtal(4)
#define R1 digtal(5)
#define R2 digtal(6)
#define R3 digtal(7)

void Track_Init(void);
int digtal(int channel);


#endif


/*
	//API接口说明
    调用L1，L2,L3,M,R1,R2,R3直接读取传感器数值
	返回值为1表示高电平，处于黑色；返回值为1表示低电平，处于白色
	//接线说明
	L3 接 A1
	L2 接 A2
	L1 接 A3
	M  接 A4
	R1 接 A5
	R2 接 A6
	R3 接 A7
*/

