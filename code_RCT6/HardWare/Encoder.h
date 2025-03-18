#ifndef __ENCODER_H
#define __ENCODER_H

void EncoderL_Init(void);
int Read_LEncoder(void);
void TIM5_IRQHandler(void);
void EncoderR_Init(void);
int Read_REncoder(void);
void TIM3_IRQHandler(void);

#endif
