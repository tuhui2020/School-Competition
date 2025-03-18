#include "stm32f10x.h"                  // Device header


void Track_Init(void)
{
	/*开启时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);		//开启GPIOA的时钟
	
	/*GPIO初始化*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 |   GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);		                                 				//将引脚初始化为浮空输入
}

int digtal(int channel)
{
	switch(channel)
	{
		case 1:
			if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_0) == Bit_SET)
			{
				//高电平
				return 1;
			}else 
			{
				return 0;
			}
			break;
		case 2:
			if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_1) == Bit_SET)  return 1;
			else return 0;
			break;
		case 3:
			if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_2) == Bit_SET)  return 1;
			else return 0;
			break;
		case 4:
			if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_3) == Bit_SET)  return 1;
			else return 0;
			break;
		case 5:
			if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13) == Bit_SET)  return 1;
			else return 0;
			break;
		case 6:
			if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14) == Bit_SET)  return 1;
			else return 0;
			break;
		case 7:
			if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_15) == Bit_SET)  return 1;
			else return 0;
			break;
	}
	return 0;
}
