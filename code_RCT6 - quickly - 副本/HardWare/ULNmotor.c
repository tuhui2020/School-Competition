#include "stm32f10x.h"                  // Device header
#include "delay.h"
uint16_t Delay_time=1000;
uint16_t ULN_Num=2;
void ULNmotor_Init(void)
{
	RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 |GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}

void ULNmotor(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_9 );
	GPIO_ResetBits(GPIOA, GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12);
	Delay_us(Delay_time);   
	
	GPIO_SetBits(GPIOA,GPIO_Pin_9| GPIO_Pin_10 );
	GPIO_ResetBits(GPIOA,GPIO_Pin_11 | GPIO_Pin_12);
	Delay_us(Delay_time);
	
	GPIO_SetBits(GPIOA,GPIO_Pin_10 );
	GPIO_ResetBits(GPIOA, GPIO_Pin_9 | GPIO_Pin_11 | GPIO_Pin_12);
	Delay_us(Delay_time);   
	
	GPIO_SetBits(GPIOA,GPIO_Pin_10 | GPIO_Pin_11 );
	GPIO_ResetBits(GPIOA,GPIO_Pin_9 | GPIO_Pin_12);
	Delay_us(Delay_time);
	
	GPIO_SetBits(GPIOA,GPIO_Pin_11);
	GPIO_ResetBits(GPIOA, GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_12);
	Delay_us(Delay_time);  
	
	GPIO_SetBits(GPIOA,GPIO_Pin_11| GPIO_Pin_12 );
	GPIO_ResetBits(GPIOA,GPIO_Pin_9 | GPIO_Pin_10);
	Delay_us(Delay_time);
	
	GPIO_SetBits(GPIOA,GPIO_Pin_12 );
	GPIO_ResetBits(GPIOA, GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11);
	Delay_us(Delay_time);   

	GPIO_SetBits(GPIOA,GPIO_Pin_12| GPIO_Pin_9 );
	GPIO_ResetBits(GPIOA,GPIO_Pin_10 | GPIO_Pin_11);
	Delay_us(Delay_time);
	
	GPIO_ResetBits(GPIOA,GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12);
	
}

void ULN(int uln){
	while (ULN_Num!=uln){
		if (ULN_Num==0){
			uint16_t w=170;
			while (w--){
				ULNmotor();
			}
		}else {
			uint16_t w=171;
			while (w--){
				ULNmotor();
			}
		}
		ULN_Num=(ULN_Num+1)%3;
	}
}
