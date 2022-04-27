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
enum LedState{TURN_RIGHT, WAIT_FOR_BUTTON};
enum LedState eLedState = WAIT_FOR_BUTTON;

unsigned char ucStepCounter;

int main ()
{	
	LedInit();
	KeyboardInit();
	
	ucStepCounter = 0;
	
	while(1)
	{	
		switch(eLedState)
		{
			case TURN_RIGHT:

				ucStepCounter++;
			
				if(ucStepCounter > 3)
				{
					ucStepCounter = 0;
					eLedState = WAIT_FOR_BUTTON;
				}
				
				else
				{
					LedStepRight();
				}
				break;
				
				case WAIT_FOR_BUTTON:
					
					if(eKeyboardRead() == BUTTON_0)
					{
						eLedState = TURN_RIGHT;
					}
				break;	
		}
		delay(100);
	}
}
