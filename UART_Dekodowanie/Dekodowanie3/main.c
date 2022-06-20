#include "strings.h"
#include "uart.h"
#include "servo.h"
#include "decoding.h"

#define RECIEVER_SIZE 24

int main ()
{	
	char cDestination[RECIEVER_SIZE];
	
	UART_InitWithInt(9600);
	ServoInit(50);
	
	while(1)
	{
		if (eReciever_GetStatus() == READY)
		{
			Reciever_GetStringCopy(cDestination);
			DecodeMsg(cDestination);
		}
		
		if ((ucTokenNr > 0) && (asToken[0].eType == KEYWORD))
		{
			switch (asToken[0].uValue.eKeyword)
			{	
				case CAL:
					ServoCallib();
				break;
				
				case GT:
					if (asToken[1].eType == NUMBER)
					{
						ServoGoTo(asToken[1].uValue.uiNumber);
					}
				break;
			}
		}
	}
}
