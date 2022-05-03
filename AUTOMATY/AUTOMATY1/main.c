#include "led.h"

void delay(unsigned long int uiMiliseconds)
{
	unsigned long int uliCycleCounter;
	for(uliCycleCounter = 0 ; uliCycleCounter < uiMiliseconds ; uliCycleCounter++)
	{
		unsigned long int i;
		for(i = 0 ; i < 7500 ; i++){}
	}
}
enum LedState{LED_LEFT, LED_RIGHT};
enum LedState eLedState = LED_LEFT;

int main ()
{	
	LedInit();
	
	while(1)
	{
		delay(250);
		
		switch(eLedState)
		{
			case LED_LEFT:
			LedStepLeft();
			eLedState = LED_RIGHT;
			break;
			
			case LED_RIGHT:
			LedStepRight();
			eLedState = LED_LEFT;
			break;
		}
	}
}
