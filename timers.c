#include "stm32f10x.h"
//SEGUNDO MOTOR TIMER 3
//primer motor timer 2

//SALIDA CANAL 2 TIMMER 2: Pin PA1
//SALIDA CANAL 2 TIMMER 3: Pin PA7


/*
	Valores para los diferentes pulsos
							0.7ms/25ms		1.5ms/25ms		2.3ms/25ms
	ARR:					64284					64284					64284
	PSC:					27							27						27
	CCR2					1800					3857					5914
	
	*/

void inictim2(){
RCC->APB1ENR |= (1 << 0);	//enable TIM2 clk
	TIM2->PSC=27;
	TIM2->ARR=64284;
	//TIM2->CCR2 = 3273;
	TIM2->CCMR1 |= (1 << 14) | (1 << 13); //select pwm mode ch2
	TIM2->CCER	|=	(1 << 4);	//enable ch2
	TIM2->CR1		|=	(1 << 0); //enable timer
}

void inictim3(){
RCC->APB1ENR |= (1 << 0);	//enable TIM3 clk
	TIM3->PSC=27;
	TIM3->ARR=64284;
	TIM3->CCMR1 |= (1 << 14) | (1 << 13); //select pwm mode ch2
	TIM3->CCER	|=	(1 << 4);	//enable ch2
	TIM3->CR1		|=	(1 << 0); //enable timer
}

//0°->90°->180°
void motoruno1(){

		for (volatile int i = 0;i < 100;i++)
			{
				TIM2->CCR2 = 1800;
				for (int j = 0;j < 65453;j++);
			}

		for (volatile int i = 100;i > 0;i--)
			{
				TIM2->CCR2 = 3857;
				for (int j = 0;j < 65453;j++);
			}
			
			for (volatile int i = 0;i < 100;i++)
			{
				TIM2->CCR2 = 5914;
				for (int j = 0;j < 65453;j++);
			}
}



//180°->90°->0°
void motoruno2(){
	
		for (volatile int i = 0;i < 100;i++)
			{
				TIM2->CCR2 = 5914;
				for (int j = 0;j < 65453;j++);
			}

		for (volatile int i = 100;i > 0;i--)
			{
				TIM2->CCR2 = 3857;
				for (int j = 0;j < 65453;j++);
			}
			
			for (volatile int i = 0;i < 100;i++)
			{
				TIM2->CCR2 = 1800;
				for (int j = 0;j < 65453;j++);
			}
	}



	
	
//0°->90°->180°
	void motordos1(){
		//SEGUNDO MOTOR TIMER 3
	
		for (volatile int i = 0;i < 100;i++)
			{
				TIM3->CCR2 = 1800;
				for (int j = 0;j < 65453;j++);
			}

		for (volatile int i = 100;i > 0;i--)
			{
				TIM3->CCR2 = 3857;
				for (int j = 0;j < 65453;j++);
			}
			
			for (volatile int i = 0;i < 100;i++)
			{
				TIM3->CCR2 = 5914;
				for (int j = 0;j < 65453;j++);
			}
	}


	
	//180°->90°->0°
	void motordos2(){
	for (volatile int i = 0;i < 100;i++)
			{
				TIM3->CCR2 = 5914;
				for (int j = 0;j < 65453;j++);
			}

		for (volatile int i = 100;i > 0;i--)
			{
				TIM3->CCR2 = 3857;
				for (int j = 0;j < 65453;j++);
			}
			
			for (volatile int i = 0;i < 100;i++)
			{
				TIM3->CCR2 = 1800;
				for (int j = 0;j < 65453;j++);
			}
		
	}
	

	
