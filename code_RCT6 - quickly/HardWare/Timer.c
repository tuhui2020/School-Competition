#include "stm32f10x.h"                  // Device header
#include "Timer.h"
#include "HCSR04.h"
extern uint16_t Time;
void Time_Init(){
	Time=0;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE); 			//ʱ��ʹ��

	TIM_InternalClockConfig(TIM4);
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period = 7199; 						//��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler =0; 						//����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; 		//����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); 				//����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
 
	TIM_ClearFlag(TIM4, TIM_FLAG_Update);  
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE ); 						//ʹ��ָ����TIM4�ж�,��������ж�
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;  				//TIM4�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; 		//��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;  			//�����ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure); 								//��ʼ��NVIC�Ĵ���

	TIM_Cmd(TIM4,ENABLE);     //����TIM4				

}


void TIM4_IRQHandler(void)   //TIM4�ж�		
{
   if (TIM_GetITStatus(TIM4, TIM_IT_Update) != SET)  
   {
	   if (GPIO_ReadInputDataBit(Echo_Port,Echo_Pin) == 1){
		Time++;
	   }
       TIM_ClearITPendingBit(TIM4, TIM_IT_Update); 
   }
}