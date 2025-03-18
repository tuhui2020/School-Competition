#include "stm32f10x.h"                  // Device header
#include "INCLUDE.h"
int QR_num=2;
int line3[7]={0,1,1,2,2,3,3};
int Uln[7][3]={{0,0,0},{1,0,2},{1,2,0},{2,0,1},{0,2,1},{2,1,0},{0,1,2}};
	//1为red，2为green，0为blue
void Getline(int direction){
	while (1){
		if (L1+L2+L3+M>=4||M+R1+R2+R3>=4||L1+L2+L3+M+R1+R2+R3==0){motor_stop();break;}
		if (direction==1){
			if (L3==1){
				motor_r(100);
				motor_l(30);
				//Delay_ms(1); 
			}else if (L2==1){
				motor_r(90);
				motor_l(50);
				//Delay_ms(1);
			}else if (R3==1){
				motor_l(100);
				motor_r(30);
				//Delay_ms(1);
			}else if (R2==1){
				motor_l(90);
				motor_r(50);
				//Delay_ms(1);
			}else if (L1==1){
				motor_r(80);
				motor_l(60);
				//Delay_ms(1);
			}else if (R1==1){
				motor_l(80);
				motor_r(60);
				//Delay_ms(1);
			}else if (M==1){
				motor_r(70);
				motor_l(70);
				//Delay_ms(1);
			}
		}else {
			int t=direction/5;
			while (t--){
				if (L3==1){
					motor_r(100);
					motor_l(30);
					//Delay_ms(1); 
				}else if (L2==1){
					motor_r(90);
					motor_l(50);
					//Delay_ms(1);
				}else if (R3==1){
					motor_l(100);
					motor_r(30);
					//Delay_ms(1);
				}else if (R2==1){
					motor_l(90);
					motor_r(50);
					//Delay_ms(1);
				}else if (L1==1){
					motor_r(80);
					motor_l(60);
					//Delay_ms(1);
				}else if (R1==1){
					motor_l(80);
					motor_r(60);
					//Delay_ms(1);
				}else if (M==1){
					motor_r(70);
					motor_l(70);
					//Delay_ms(1);
				}
				Delay_ms(5);
			}
			break;
		}
	}
}

void Getline1(void){
	//if (Get_camera()==1){
	//	Get_object();
	//}
	Getline(1);
	//到达左转弯
	//后退到二维码位置
	//	motor_l(-50);
	//	motor_r(-50);
	//	Delay_ms(1300);
	//	motor_stop();
	//	//右转弯90
	//	motor_l(50);
	//	motor_r(-50);
	//	Delay_ms(500);
	//	//停止等待扫码
	//	motor_stop();
	//	motor_l(-20);
	//	motor_r(-20);
	//	Delay_ms(1500);
	//	motor_stop();
	//	//sent_camera(1);
	//	Delay_ms(2000);
	//	//左转弯至能巡线位置
	//	while(L1+M+R1==0){
	//		motor_r(20);
	//		motor_l(20);
	//		Delay_ms(5);
	//	}
	//	turn_left();
	//	//再次巡线至左转位置并左转
	//	Getline(1);
	turn_left();
	motor_stop();
}

void Getline2(void){
	//绕过第一个路口，走到一号台
	Getline(1);
	motor_l(50);
	motor_r(50);
	Delay_ms(300);
	motor_l(0);
	motor_r(0);
	//Getline(1); 
	//ULN(Uln[QR_num][0]);
	//Put_object(1);
	//倒车到路口并转弯
	//while (L1+M+R1==0){
	//	motor_l(-50);
	//	motor_r(50);
	//}
	//motor_stop();
	//motor_l(50);
	//motor_r(50);
	//Getline(1);
	//motor_l(50);
	//motor_r(50);
	//Delay_ms(300);
	//motor_stop( );
	motor_l(-50);
	motor_r(50);
	Delay_ms(400);
	while (L1+M+R1==0){
		motor_l(-50);
		motor_r(50);
	}
	motor_stop();
	//前往二号台
	Getline(1);
	motor_l(50);
	motor_r(50);
	Delay_ms(150);
	motor_stop();
	motor_l(50);
	motor_r(-50);
	Delay_ms(300);
	while (L1+R1+M==0){
		motor_l(50);
		motor_r(-50);
	}
	motor_stop();
	Getline(1);
	motor_l(50);
	motor_r(50);
	Delay_ms(150);
	//Getline(1);
	//ULN(Uln[QR_num][1]);
	//Put_object(2);
	motor_l(-50);
	motor_r(50);
	Delay_ms(300);
	while (L1+R1+M==0){
		motor_l(-50);
		motor_r(50);
	}
	motor_stop();
	Getline(1);
	motor_stop();
	//Getline3();

}
void Getline3(void){
	//QR_num=1走左边一条线
	if (line3[QR_num]==3){
		motor_l(50);
		motor_r(50);
		Delay_ms(1000);
		motor_stop();
		motor_l(-50);
		motor_r(50);
		Delay_ms(20);
		motor_stop();
		while (L1+R1+M==0){
			motor_l(20);
			motor_r(20);
		}
		motor_stop();
		//motor_l(20);
		//motor_r(20);
		//Delay_ms(500);
		//motor_stop();
		//motor_l(50);
		//motor_r(-50);
		//Delay_ms(650);
		//motor_stop();
		Getline(1);
		motor_l(50);
		motor_r(50);
		Delay_ms(200);
		motor_stop();
		buzzer_on();
		Getline(1);
		motor_l(50);
		motor_r(50);
		Delay_ms(1200);
		motor_l(50);
		motor_r(-50);
		Delay_ms(550);
		motor_l(50);
		motor_r(50);
		Delay_ms(300);
		motor_stop();
		Delay_ms(10000);
	}else if (line3[QR_num]==2){
		motor_l(20);
		motor_r(20);
		Delay_ms(500);
		motor_stop();
		Getline(1);
		motor_l(50);
		motor_r(50);
		Delay_ms(200);
		motor_stop();
		buzzer_on();
		Getline(1);
		motor_l(50);
		motor_r(50);
		Delay_ms(1200);
		motor_stop();
		Delay_ms(10000);
	}else {
		motor_l(50);
		motor_r(50);
		Delay_ms(600);
		motor_stop();
		motor_l(50);
		motor_r(-50);
		Delay_ms(350);
		motor_stop();
		motor_l(50);
		motor_r(50);
		Delay_ms(400);
		motor_stop();
		while (L1+R1+M==0){
			motor_l(40);
			motor_r(40);
		}
		motor_stop();
		Getline(1);
		motor_l(50);
		motor_r(50);
		Delay_ms(200);
		motor_stop();
		buzzer_on();
		Getline(1);
		motor_l(50);
		motor_r(50);
		Delay_ms(1000);
		motor_l(-50);
		motor_r(50);
		Delay_ms(580);
		motor_l(50);
		motor_r(50);
		Delay_ms(300);
		motor_stop();
		Delay_ms(10000);
	}

}
void action1(void){
	motor_l(100);
	motor_r(100);
	Delay_ms(400);
	motor_l(100);
	motor_r(-100);
	Delay_ms(400);
	motor_l(100);
	motor_r(100);
	Delay_ms(430);
	motor_l(0);
	motor_r(0);
	Delay_ms(5000);
	motor_l(100);
	motor_r(100);
	Delay_ms(620);
	motor_l(-100);
	motor_r(100);
	Delay_ms(400);
	motor_stop();
	while (L1+M+R1==0){
		motor_l(50);
		motor_r(50);
	}
	motor_stop();
	motor_r(50);
	motor_l(50);
	Delay_ms(200);
	while (L1+M+R1==0){
		motor_l(50);
		motor_r(-50);
	}
	motor_stop();
	Delay_ms(500);
	
}

void turn_left(void){
	motor_l(50);
	motor_r(50);
	Delay_ms(100);
	motor_stop();
	while (L1+M+R1==0){
		motor_l(-50);
		motor_r(50);
	}
	
	//Delay_ms(650);
	motor_stop();
}

void turn_right(void){
	motor_l(20);
	motor_r(20);
	Delay_ms(550);
	motor_stop();
	while (L1+M+R1==0){
		motor_l(20);
		motor_r(-20);
	}
	motor_stop();
}

void motor_back(void){
	motor_l(50);
	motor_r(-50);
	Delay_ms(1300);
	motor_stop();
}
void motor_stop(void){
	motor_l(0);
	motor_r(0);
}
