#include "INCLUDE.h"

void Init(void){
	motor_Init();
	OLED_Init();
	Buzzer_Init();
	Track_Init();
	ULNmotor_Init();
	HCSR04_Init();
}
