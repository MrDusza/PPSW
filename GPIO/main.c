#include <LPC21xx.H>

#define LED0_bm (1 << 16)
#define LED1_bm (1 << 17)
#define LED2_bm (1 << 18)
#define LED3_bm (1 << 19)

#define BUT0_bm (1 << 4)
#define BUT1_bm (1 << 6)
#define BUT2_bm (1 << 5)
#define BUT3_bm (1 << 7)

void delay(unsigned long int uiMiliseconds)
{
	unsigned long int i;
	for(i = 0 ; i < uiMiliseconds ; i++)
	{
		unsigned long int i;
		for(i = 0 ; i < 7500 ; i++){}
	}
}

void LedInit()
{
	IO1DIR = IO1DIR | LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	
	IO1SET = LED0_bm;
}

void LedOn(unsigned char ucLedIndeks)
{
	IO1CLR = IO1CLR | LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	
	switch(ucLedIndeks)
	{
		case 0:
			IO1SET = LED0_bm;
			break;
		case 1:
			IO1SET = LED1_bm;
			break;
		case 2:
			IO1SET = LED2_bm;
			break;
		case 3:
			IO1SET = LED3_bm;
			break;
		default:
			break;
	}
}

void KeyboardInit()
{
	IO0DIR = IO0DIR & ~(BUT0_bm | BUT1_bm | BUT2_bm | BUT3_bm);
}

enum KeyboardState {RELASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};

enum KeyboardState eKeyboardRead()
{
	if((IO0PIN & BUT0_bm) == 0)
	{
		return(BUTTON_0);
	}
	else if((IO0PIN & BUT1_bm) == 0)
	{
		return(BUTTON_1);
	}
	else if((IO0PIN & BUT2_bm) == 0)
	{
		return(BUTTON_2);
	}
	else if((IO0PIN & BUT3_bm) == 0)
	{
		return(BUTTON_3);
	}
	else
	{
		return(RELASED);
	}
}



enum StepDirection {LEFT, RIGHT};

void LedStep(enum StepDirection Direction)
{
	static unsigned int uiModuloCounter = 0;
	
	switch(Direction)
	{
		case LEFT:
			uiModuloCounter++;
			break;
		
		case RIGHT:
			uiModuloCounter--;
			break;
		
		default:
			break;
	}
	LedOn(uiModuloCounter % 4);
}

void LedStepLeft()
{
	LedStep(LEFT);
}

void LedStepRight()
{
	LedStep(RIGHT);
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
	
