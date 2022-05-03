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
enum LedState{TURN_LEFT, TURN_RIGHT};
enum LedState eLedState = TURN_RIGHT;

unsigned char ucStepCounter;

int main ()
{	
	LedInit();
	
	ucStepCounter = 0;
	
	while(1)
	{	
		switch(eLedState)
		{
			case TURN_LEFT:
				ucStepCounter++;
			
				if(ucStepCounter > 3)
				{
					ucStepCounter = 0;
					eLedState = TURN_RIGHT;
				}
				
				else
				{
					LedStepRight();
				}
				break;
				
				case TURN_RIGHT:
					ucStepCounter++;
					
				if(ucStepCounter > 3)
				{
					ucStepCounter = 0;
					eLedState = TURN_LEFT;
				}
				
				else
				{
					LedStepLeft();
				}
				break;	
		}
		delay(250);
	}
}
