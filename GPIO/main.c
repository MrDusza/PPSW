#include "led.h"
#include "keyboard.h"

void delay(unsigned long int uiMiliseconds)
{
	unsigned long int uliCycleCounter;
	for(uliCycleCounter = 0 ; uliCycleCounter < uiMiliseconds ; uliCycleCounter++)
	{
		unsigned long int i;
		for(i = 0 ; i < 7500 ; i++){}
	}
}

int main ()
{	
	LedInit();
	KeyboardInit();
	
	while(1)
	{
		switch(eKeyboardRead())
		{
			case BUTTON_1:
				LedStepRight();
				break;
			
			case BUTTON_2:
				LedStepLeft();
				break;
			
			default:
				break;
		}
		delay(250);
	}
}
	
