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
	/*开启时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	//开启GPIOA的时钟
															//使用各个外设前必须开启时钟，否则对外设的操作无效
	
	/*GPIO初始化*/
	GPIO_InitTypeDef GPIO_InitStructure;					//定义结构体变量
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		//GPIO模式，赋值为推挽输出模式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11;				//GPIO引脚，赋值为第8.9.10.11号引脚
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//GPIO速度，赋值为50MHz
	
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