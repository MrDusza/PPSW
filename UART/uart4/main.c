#include "keyboard.h"
#include "servo.h"
#include "uart.h"
#include "led.h"

extern char cOdebranyZnak;

int main ()
{	
	unsigned int uiCurrentPosition = 0;
	
	UART_InitWithInt(9600);
	LedInit();
	ServoInit(50);
	
	while(1)
	{
		switch(cOdebranyZnak)
		{
			case '1':
			uiCurrentPosition += 12;
			ServoGoTo(uiCurrentPosition);
			cOdebranyZnak = 0;
			break;
			
			case 'c':
			ServoCallib();
			cOdebranyZnak = 0;
			uiCurrentPosition = 0;
			break;
		}
	}
}
