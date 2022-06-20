#include "strings.h"
#include "uart.h"

#define RECIEVER_SIZE 4
#define TERMINATOR '\r'
#define NULL '\0'

extern char cOdebranyZnak;

enum eRecieverStatus {EMPTY, READY, OVERFLOW};

struct RecieverBuffer
{ 
	char cData[RECIEVER_SIZE];
	unsigned char ucCharCtr;
	enum eRecieverStatus eStatus;
};

struct RecieverBuffer sRxBuff;

void Reciever_PutCharacterToBuffer(char cCharacter)
{
	if (sRxBuff.ucCharCtr == RECIEVER_SIZE)
	{
		sRxBuff.eStatus = OVERFLOW;
	}	
	
	else if (cCharacter == TERMINATOR)
	{
		sRxBuff.cData[sRxBuff.ucCharCtr] = NULL;
		sRxBuff.eStatus = READY;
		sRxBuff.ucCharCtr = 0;
	}
	
	else
	{
		sRxBuff.cData[sRxBuff.ucCharCtr] = cCharacter;
		sRxBuff.ucCharCtr++;
	}
}

enum eRecieverStatus eReciever_GetStatus(void)
{
	return sRxBuff.eStatus;
}

void Reciever_GetStringCopy(char *ucDestination)
{
	CopyString(sRxBuff.cData, ucDestination);
	sRxBuff.eStatus = EMPTY;
}

int main ()
{	
	Reciever_PutCharacterToBuffer ('k');
	Reciever_PutCharacterToBuffer ('o');
	Reciever_PutCharacterToBuffer ('d');
	Reciever_PutCharacterToBuffer (TERMINATOR);
	sRxBuff.eStatus = EMPTY;
	Reciever_PutCharacterToBuffer ('d');
	Reciever_PutCharacterToBuffer ('o');
	Reciever_PutCharacterToBuffer ('k');
	Reciever_PutCharacterToBuffer ('1');
	Reciever_PutCharacterToBuffer (TERMINATOR);
}
