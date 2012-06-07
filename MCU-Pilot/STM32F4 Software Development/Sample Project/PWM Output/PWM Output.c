//**************************************//
//File:PWM Output                       //
//Date:7th Of June 2012                 //
//Author:Javen                          //
//Project:MCU-Pilot                     //
//**************************************//

#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

//Private TypeDef
TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
TIM_OCInitTypeDef TIM_OCInitStructure;
void GPIO_Config(void);

//Main Loop
int main(void)
{
	GPIO_Config();
	
//Time Base Configuration
TIM_TimeBaseStructure.TIM_Period=1999;
TIM_TimeBaseStructure.TIM_Prescaler=839;
TIM_TimeBaseStructure.TIM_ClockDivision=0;
TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	
//Output Compare Configuration OC1
TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
TIM_OCInitStructure.TIM_Pulse = 199;
TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
TIM_OC1Init(TIM3, &TIM_OCInitStructure);

//Enable OC1 Preload Config
TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
//Output Compare Configuration OC2
TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
TIM_OCInitStructure.TIM_Pulse = 99.95;
TIM_OC2Init(TIM3, &TIM_OCInitStructure);

//Enable OC2 Preload Config
TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
//Enable Autoreload Register
TIM_ARRPreloadConfig(TIM3, ENABLE);
	
//Timer 3 Counter Enable	
TIM_Cmd(TIM3, ENABLE);


}

void GPIO_Config(void)
{
//Private TypeDef
GPIO_InitTypeDef GPIO_InitStructure;

//Enable Timer 3 Clock(RCC Module)
RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

//Enable GPIOC Clock(RCC Module)
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

//GPIOC Configuration
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
GPIO_Init(GPIOC, &GPIO_InitStructure); 

//Connect Timer3 Pin to AF2
GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_TIM3);
GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_TIM3);

}