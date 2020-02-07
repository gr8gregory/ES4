#include "lcd.h"
#include "utils.h"

void GPIO_CLOCK_ENABLE(){
	
	// Enable GPIO port B clock
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOEEN;
}

void GPIO_Init(void){
	
		GPIO_CLOCK_ENABLE();
	// PE8 - RS
	// PE11 - E
	// PE12 - PE15
	
	CLR_BITS(GPIOE->MODER, 0xFFC3U <<(8*2)); // Clear Bits to 0
	SET_BITS(GPIOE->MODER, 0x5541U <<(8*2));	// Set the bits to General purpose output Mode (01)
	CLR_BITS(GPIOE->OTYPER, 0xF9U <<(8));	// Set bits to Push-pull
}
