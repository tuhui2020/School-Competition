#include "stm32f10x.h"                  // Device header
#include "delay.h"

void Buzzer_Init(void)
{
	/*����ʱ��*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	//����GPIOA��ʱ��
															//ʹ�ø�������ǰ���뿪��ʱ�ӣ����������Ĳ�����Ч
	
	/*GPIO��ʼ��*/
	GPIO_InitTypeDef GPIO_InitStructure;					//����ṹ�����
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		//GPIOģʽ����ֵΪ�������ģʽ
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 ;				//GPIO���ţ���ֵΪ��12������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//GPIO�ٶȣ���ֵΪ50MHz
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);					//����ֵ��Ĺ���������ݸ�GPIO_Init����
															//�����ڲ����Զ����ݽṹ��Ĳ���������Ӧ�Ĵ���
	GPIO_SetBits(GPIOA, GPIO_Pin_8);														//ʵ��GPIOA�ĳ�ʼ��
}

void buzzer_on()
{
		int t=3;
		while (t--)
		{
			GPIO_ResetBits(GPIOA, GPIO_Pin_8);
			Delay_ms(500);
			GPIO_SetBits(GPIOA, GPIO_Pin_8);
			Delay_ms(500);
		}
}

void buzzer_off()
{
			GPIO_SetBits(GPIOA, GPIO_Pin_8);
}
