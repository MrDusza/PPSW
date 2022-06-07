#include "keyboard.h"
#include "servo.h"
#include "uart.h"
#include "led.h"

extern char cOdebranyZnak;

int main ()
{	
	UART_InitWithInt(9600);
	LedInit();
	
	while(1)
	{
		if(cOdebranyZnak == 'a')
		{
			LedOn(1);
		}
		else
		{
			LedOn(4);
		}
	}
}
