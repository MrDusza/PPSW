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
enum LedState{STOP, TURN_RIGHT};
enum LedState eLedState = TURN_RIGHT;

unsigned char ucStepCounter;

int main ()
{	
	LedInit();
	KeyboardInit();
	
	while(1)
	{	
		switch(eLedState)
		{
			case TURN_RIGHT:
			
				if(eKeyboardRead() == BUTTON_0)
				{
					eLedState = STOP;
				}
				
				else
				{
					LedStepRight();
				}
				break;
				
			case STOP:
			
				if(eKeyboardRead() == BUTTON_1)
				{
					eLedState = TURN_RIGHT;
				}
				break;	
		}
		delay(100);
	}
}
