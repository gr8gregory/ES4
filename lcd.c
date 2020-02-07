#include "lcd.h"
#include <stdio.h>
#include <stdarg.h>
void LCDcmd(uint8_t value){
	Delay_ms(2);
	LCD_E_LO;
	LCD_RS_IR;
	
	LCD_E_HI;
	LCD_BUS(HI_NIBBLE(value));
	LCD_E_LO;
	
	LCD_E_HI;
	LCD_BUS(LO_NIBBLE(value));
	LCD_E_LO;
	
	Delay_ms(2);
}

void LCDdata(uint8_t value){
	
	Delay_ms(2);
	LCD_E_LO;
	LCD_RS_DR;
	
	LCD_E_HI;
	LCD_BUS(HI_NIBBLE(value));
	LCD_E_LO;
	
	LCD_E_HI;
	LCD_BUS(LO_NIBBLE(value));
	LCD_E_LO;
	
	Delay_ms(2);
}

void LCDinit(void){
	Delay_ms(5);
	LCD_E_HI;
  LCD_BUS( 0x03 );      // wake up display & sync
  LCD_E_LO;
 
  Delay_ms( 5 );

  LCD_E_HI;
  LCD_BUS( 0x03 );      // wake up display & sync
  LCD_E_LO;

  Delay_ms( 1 );  

   
  LCD_E_HI;
  LCD_BUS( 0x03 );      // wake up display & sync
  LCD_E_LO;
   
  LCD_E_HI;
  LCD_BUS( 0x02 );      // wake up display & sync - go to 4-bit mode
  LCD_E_LO;

  Delay_ms( 2 );

// now that we're sync'd and in 4-bit mode, issue commands to configure the display

  LCDcmd( LCD_CMD_FUNCTION | LCD_FUNCTION_4BIT | LCD_FUNCTION_2LINES | LCD_FUNCTION_5X8FONT );
  LCDcmd( LCD_CMD_DISPLAY | LCD_DISPLAY_OFF );
  LCDclear();
  LCDcmd( LCD_CMD_ENTRY | LCD_ENTRY_MOVE_CURSOR | LCD_ENTRY_INC );
  LCDcmd( LCD_CMD_DISPLAY | LCD_DISPLAY_ON | LCD_DISPLAY_NOCURSOR | LCD_DISPLAY_NOBLINK );

}
void LCDclear(void){
	
	LCDcmd(0x1);
}



void LCDprintf( char *fmt, ...){
	
	va_list args;
	char buffer[80];
	va_start(args, fmt);
	vsnprintf(buffer, 80, fmt, args);
	va_end(args);
	LCDputs(buffer);
	
}

void LCDputc(unsigned char cx){
	
	LCDdata(cx);
}

void LCDputs( char *str ){
	
	while (*str){
			LCDputc( *str++);
	}
	
}
		
