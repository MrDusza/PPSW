#include <LPC21xx.H>
#include "led.h"
#include "timer_interrupts.h"
#include "servo.h"

#define SERVO_OFFSET 0
#define DETECTOR_bm (1<<10)

enum ServoState {CALLIB, IDLE, IN_PROGRESS, SHIFT_OFFSET};

struct Servo
{
	enum ServoState eState;
	unsigned int uiCurrentPosition; 
	unsigned int uiDesiredPosition;
}; 

struct Servo sServo;

void DetectorInit()
{
	IO0DIR &= ~DETECTOR_bm;
}

enum State {ACTIVE, INACTIVE};

enum State eReadDetector()
{
	if((IO0PIN&DETECTOR_bm) == 0)
	{
		return ACTIVE;
	}
	
	else
	{
		return INACTIVE;
	}
}

void Automat()
{	
	
	static unsigned char ucShiftCounter;
	
	switch(sServo.eState)
	{
		case CALLIB:
			
		if(eReadDetector() == ACTIVE)
		{
			sServo.uiCurrentPosition = 0;
			sServo.uiDesiredPosition = 0;
			sServo.eState = SHIFT_OFFSET;
		}
		
		else
		{
			LedStepLeft();
		}
		break;
		
		case SHIFT_OFFSET:
		
		if(ucShiftCounter < SERVO_OFFSET)
			{
				LedStepRight();
				ucShiftCounter++;
				sServo.eState = SHIFT_OFFSET;
			}
			else
			{
				ucShiftCounter = 0;
				sServo.eState = IDLE;
			}
			break;
		
		case IDLE:
		
		if(sServo.uiCurrentPosition == sServo.uiDesiredPosition)
		{
			sServo.eState = IDLE;
		}
		
		else
		{
			sServo.eState = IN_PROGRESS;
		}
		break;
		
		case IN_PROGRESS:
		
		if(sServo.uiDesiredPosition > sServo.uiCurrentPosition)
		{
			sServo.uiCurrentPosition++;
			LedStepRight();
		}
		
		else if(sServo.uiDesiredPosition < sServo.uiCurrentPosition)
		{
			sServo.uiCurrentPosition--;
			LedStepLeft();
		}
		
		else
		{
			sServo.eState = IDLE;
		}
		break;
	}
}

void ServoInit(unsigned int uiServoFrequency)
{
	DetectorInit();
	sServo.eState = CALLIB;
	LedInit();
	Timer1Interrupts_Init(1000000 / uiServoFrequency, &Automat);
}

void ServoCallib(void)
{
	sServo.eState = CALLIB;
}

void ServoGoTo(unsigned int uiPosition)
{
	while(sServo.eState != IDLE){}
	sServo.uiDesiredPosition = uiPosition;
	
	
}

