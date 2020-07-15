#include "stm8s.h"

void delay_ms(uint16_t u16Delay);

void delay_ms(uint16_t u16Delay)
{
	
	while (u16Delay) {
		TIM4_SetCounter(0);
		TIM4_ClearFlag(TIM4_FLAG_UPDATE);
		while (TIM4_GetFlagStatus(TIM4_FLAG_UPDATE) == RESET) {
		}
		--u16Delay;
	}
}

void main(void)
{
	
	CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
	GPIO_DeInit(GPIOB);
	GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_FAST);
	TIM4_TimeBaseInit(TIM4_PRESCALER_128, 125 - 1);
	TIM4_Cmd(ENABLE);
	
    while(1) {
        delay_ms(500);
		GPIO_WriteReverse(GPIOB, GPIO_PIN_5);
    }
}
