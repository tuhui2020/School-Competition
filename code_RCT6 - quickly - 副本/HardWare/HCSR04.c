#include "stm32f10x.h"                  // Device header

#include "Delay.h"
#include "HCSR04.h"
#include "Timer.h"
uint16_t Time;
void HCSR04_Init(){
	
	RCC_APB2PeriphClockCmd(Trig_RCC, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
		
	GPIO_InitStructure.GPIO_Pin = Trig_Pin;	 		// 配置连接 传感器TRIG 的单片机引脚模式
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(Trig_Port, &GPIO_InitStructure);				// 初始化 

	GPIO_InitStructure.GPIO_Pin = Echo_Pin;			// 配置连接 传感器ECHO 的单片机引脚模式
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(Echo_Port, &GPIO_InitStructure);				// 初始化 

	GPIO_ResetBits(Trig_Port,Trig_Pin);
}

void HCSR04_Start(){
	GPIO_SetBits(Trig_Port,Trig_Pin);
	Delay_us(45);
	GPIO_ResetBits(Trig_Port,Trig_Pin);
	Time_Init();

}

uint16_t HCSR04_GetValue(){
	HCSR04_Start();
	Delay_ms(1);
	//return ((Time * 0.01) * 34000) /2;
	return 1;
}