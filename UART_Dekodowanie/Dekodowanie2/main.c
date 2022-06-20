#include "strings.h"
#include "uart.h"
#include "servo.h"

int main ()
{	
	char cDestination[255];
	
	UART_InitWithInt(9600);
	ServoInit(50);
	
	while(1)
	{
		if (eReciever_GetStatus() == READY)
		{
			Reciever_GetStringCopy(cDestination);
		}
		
		if (eCompareString(cDestination, "callib") == EQUAL)
		{
			ServoCallib();
		}
		else if (eCompareString(cDestination, "left") == EQUAL)
		{
			ServoGoTo(12);
		}
		else if (eCompareString(cDestination, "right") == EQUAL)
		{
			ServoGoTo(36);
		}
	}
}
