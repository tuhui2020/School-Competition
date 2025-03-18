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
	//API�ӿ�˵��
    ����L1��L2,L3,M,R1,R2,R3ֱ�Ӷ�ȡ��������ֵ
	����ֵΪ1��ʾ�ߵ�ƽ�����ں�ɫ������ֵΪ1��ʾ�͵�ƽ�����ڰ�ɫ
	//����˵��
	L3 �� A1
	L2 �� A2
	L1 �� A3
	M  �� A4
	R1 �� A5
	R2 �� A6
	R3 �� A7
*/

