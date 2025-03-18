#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "Timer.h"
#include "IC.h"

#define S0 GPIO_Pin_8
#define S1 GPIO_Pin_9
#define S2 GPIO_Pin_10
#define S3 GPIO_Pin_11

void ColorF_Init(void)
{
	/*����ʱ��*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	//����GPIOA��ʱ��
															//ʹ�ø�������ǰ���뿪��ʱ�ӣ����������Ĳ�����Ч
	
	/*GPIO��ʼ��*/
	GPIO_InitTypeDef GPIO_InitStructure;					//����ṹ�����
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		//GPIOģʽ����ֵΪ�������ģʽ
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11;				//GPIO���ţ���ֵΪ��8.9.10.11������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//GPIO�ٶȣ���ֵΪ50MHz
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
}

void ColorF_start()
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);
}

void ColorF_GetGreen()
{
	GPIO_SetBits(GPIOA,S2);
	GPIO_SetBits(GPIOA,S3);
	TIM_Cmd(TIM3, ENABLE);
		
}

void ColorF_GetRed()
{
	GPIO_ResetBits(GPIOA,S2);
	GPIO_ResetBits(GPIOA,S3);
	TIM_Cmd(TIM3, ENABLE);
		
}

void ColorF_GetBlue()
{
	GPIO_ResetBits(GPIOA,S2);
	GPIO_SetBits(GPIOA,S3);
	TIM_Cmd(TIM3, ENABLE);
		
}

void ColorF_Out_Freq_100()
{
	GPIO_SetBits(GPIOA,S0);
	GPIO_SetBits(GPIOA,S1);
}

void ColorF_Out_Freq_20()
{
	GPIO_SetBits(GPIOA,S0);
	GPIO_ResetBits(GPIOA,S1);
}

void ColorF_Out_Freq_2()
{
	GPIO_ResetBits(GPIOA,S0);
	GPIO_SetBits(GPIOA,S1);
}

void ColorF_Out_Freq_0()
{
	GPIO_ResetBits(GPIOA,S0);
	GPIO_ResetBits(GPIOA,S1);
}