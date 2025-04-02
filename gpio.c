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

	//alternate function remap
	AFIO->MAPR &= ~((1 << 9)|(1 << 8));
	GPIOA ->CRL |= (1 << 29);
	GPIOA ->CRL &= ~(1 << 28);
	GPIOA ->CRL |= (1 << 31);
	GPIOA ->CRL &= ~ (1 << 30);
	
}

