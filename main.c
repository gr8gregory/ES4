//-------------------------------------------------------------------
// main.c - Initalize GPIO's, then run the joystick function
//
//
// copyright Gregory Huras, Caleb Hoeksema
//-------------------------------------------------------------------
#include "lcd.h"
#include "utils.h"
#include "GPIO.h"

int main(void){

	System_Clock_Init();
	GPIO_Init();
	
	LCDinit();
	unsigned int count = 0;
	
	while (1)
		LCDprintf("0123456789ABCDEF");
	
} //main()
