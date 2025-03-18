#include "stm32f10x.h"                  // Device header
#include "Timer.h"
#include "HCSR04.h"
extern uint16_t Time;
void Time_Init(){
	Time=0;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE); 			//时钟使能

	TIM_InternalClockConfig(TIM4);
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period = 7199; 						//设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
	TIM_TimeBaseStructure.TIM_Prescaler =0; 						//设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; 		//设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); 				//根据指定的参数初始化TIMx的时间基数单位
 
	TIM_ClearFlag(TIM4, TIM_FLAG_Update);  
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE ); 						//使能指定的TIM4中断,允许更新中断
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;  				//TIM4中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; 		//先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;  			//从优先级0级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure); 								//初始化NVIC寄存器

	TIM_Cmd(TIM4,ENABLE);     //禁用TIM4				

}


void TIM4_IRQHandler(void)   //TIM4中断		
{
   if (TIM_GetITStatus(TIM4, TIM_IT_Update) != SET)  
   {
	   if (GPIO_ReadInputDataBit(Echo_Port,Echo_Pin) == 1){
		Time++;
	   }
       TIM_ClearITPendingBit(TIM4, TIM_IT_Update); 
   }
}