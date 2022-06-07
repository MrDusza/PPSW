#include "keyboard.h"
#include "servo.h"
#include "uart.h"
#include "led.h"

extern char cOdebranyZnak;

int main ()
{	
	UART_InitWithInt(9600);
	LedInit();
	ServoInit(50);
	
	while(1)
	{
		switch(cOdebranyZnak)
		{
			case '1':
			ServoGoTo(12);
			break;
			
			case '2':
			ServoGoTo(24);
			break;
			
			case '3':
			ServoGoTo(36);
			break;
			
			case 'c':
			ServoCallib();
			break;
		}
		
		switch(eKeyboardRead())
		{
			case BUTTON_0:
			ServoCallib();
			break;
			
			case BUTTON_1:
			ServoGoTo(12);
			break;
				
			case BUTTON_2:
			ServoGoTo(24);
			break;
				
			case BUTTON_3:
			ServoGoTo(36);
			break;
				
			case RELASED:
			break;
		}
	}
}
