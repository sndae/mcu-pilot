//**************************************//
//File:PWM Input-Output                 //
//Date:13th Of June 2012                 //
//Author:Javen                          //
//Project:MCU-Pilot                     //
//**************************************//

#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

//Calling TimeBase and OC Module
TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
TIM_OCInitTypeDef TIM_OCInitStructure;

//Functions
void GPIO_Module(void);
void OC_Module(void);
//void IC_Module(void);

//Variable Declaration
__I  uint16_t Period = 4000;//Constant Value
__IO uint16_t PrescalerValue = 0;
__I  uint16_t PWM_Frequency =250; //Constant Value
__IO uint32_t TIM2_Counter_Clock = 0; //Variable Value
__IO uint16_t Channel1_Pulse=1000;
__IO uint16_t Channel2_Pulse=2000;
__IO uint16_t Channel3_Pulse=1520;
__IO uint16_t Channel4_Pulse=0;

//Main Loop
int main(void)
{

	GPIO_Module();
	OC_Module();
	//IC_Module();
	while(1);
	{
	}
}

//GPIO Module
void GPIO_Module(void)
{
//Calling GPIO Module
GPIO_InitTypeDef GPIO_InitStructure;
	
//Enabling TIM3 Clock(RCC Module)
RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
//Enabling GPIOB Clocl(RCC Module)
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	
//GPIOB Configuration
GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;
GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
GPIO_Init(GPIOA, &GPIO_InitStructure);

//Connect Timer 2 Pins to AF
GPIO_PinAFConfig(GPIOA,GPIO_PinSource0,GPIO_AF_TIM2);	
GPIO_PinAFConfig(GPIOA,GPIO_PinSource1,GPIO_AF_TIM2);	
GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_TIM2);	
GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_TIM2);
}

//OC Module
void OC_Module(void)
{
//Prescaler Value and Period Calculation
TIM2_Counter_Clock=(uint32_t) ((Period+1)*(PWM_Frequency));
PrescalerValue=(uint16_t) (((SystemCoreClock/2)/TIM2_Counter_Clock)-1);
//Period=(uint16_t) ((TIM2_Counter_Clock/PWM_Frequency)-1);

	
//TimeBase Configuration
TIM_TimeBaseStructure.TIM_Period        = Period;
TIM_TimeBaseStructure.TIM_Prescaler     = PrescalerValue;
TIM_TimeBaseStructure.TIM_ClockDivision = 0;
TIM_TimeBaseStructure.TIM_CounterMode   = TIM_CounterMode_Up;
TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
//Output Compare Configuration Channel 1-PA0
TIM_OCInitStructure.TIM_OCMode      = TIM_OCMode_PWM1;
TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
TIM_OCInitStructure.TIM_Pulse       = Channel1_Pulse;
TIM_OCInitStructure.TIM_OCPolarity  = TIM_OCPolarity_High;
TIM_OC1Init(TIM2, &TIM_OCInitStructure);
TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);
	
//Output Compare Configuration Channel 2-PA1
TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
TIM_OCInitStructure.TIM_Pulse       = Channel2_Pulse;
TIM_OC2Init(TIM2, &TIM_OCInitStructure);
TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);
	
//Output Compare Configuration Channel 3-PA2
TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
TIM_OCInitStructure.TIM_Pulse       = Channel3_Pulse;
TIM_OC3Init(TIM2, &TIM_OCInitStructure);
TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);

//Output Compare Configuration Channel 4-PA3
TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
TIM_OCInitStructure.TIM_Pulse       = Channel4_Pulse;
TIM_OC4Init(TIM2, &TIM_OCInitStructure);
TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);

TIM_ARRPreloadConfig(TIM2, ENABLE);
TIM_Cmd(TIM2, ENABLE);
}
