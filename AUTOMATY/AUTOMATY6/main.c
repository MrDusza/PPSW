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
enum LedState{STOP, TURN_RIGHT, TURN_LEFT, CHANGE_TURN_LEFT,};
enum LedState eLedState = STOP;

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
			
				if(eKeyboardRead() == BUTTON_1)
				{
					eLedState = STOP;
				}
				
				else if(eKeyboardRead() == BUTTON_3)
				{
					eLedState = CHANGE_TURN_LEFT;
				}
				
				else
				{
					LedStepRight();
				}
				break;
				
			case TURN_LEFT:
			
				if(eKeyboardRead() == BUTTON_1)
				{
					eLedState = STOP;
				}
		
				else
				{
					LedStepLeft();
				}
				break;
				
			case STOP:
			
				if(eKeyboardRead() == BUTTON_2)
				{
					eLedState = TURN_RIGHT;
				}
				else if(eKeyboardRead() == BUTTON_0)
				{
					eLedState = TURN_LEFT;
				}
				break;	
				
			case CHANGE_TURN_LEFT:
			
				if(ucStepCounter > 6)
				{
					ucStepCounter = 0;
					eLedState = TURN_LEFT;
				}
				
				else
				{
					ucStepCounter++;
					
					if(ucStepCounter%2 == 0)
					{
						LedOn(0);
					}
					
					else
					{
						LedOn(4);
					}
				}
				break;		
		}
		delay(100);
	}
}
