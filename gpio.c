#include <stm32f10x.h>

void init_gpio(void){
	//init portA
	RCC->APB2ENR |= 1 << 2; //enable clk

	/***********pwm***************/
	//PA1 mode 2MHz.
	GPIOA->CRL |= (1 << 5);
	GPIOA->CRL &= ~(1 << 4);
	//PA1 alternate function pushpull
	GPIOA->CRL |= (1 << 7);
	GPIOA->CRL &= ~(1 << 6);

	GPIOA->CRL |= (1 << 27);
	GPIOA->CRL &= ~(1 << 26);
	//PA0 alternate function pushpull
	GPIOA->CRL |= (1 << 25);
	GPIOA->CRL &= ~(1 << 24);
	
	//alternate function remap
	AFIO->MAPR &= ~((1 << 9)|(1 << 8));
	

}
