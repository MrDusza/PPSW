#include <LPC21xx.H>

#define MAX_STRING_LENGTH 254
#define NULL '\0'

void CopyString(char pcSource[], char pcDestination[])
{
	unsigned char ucCharacterCounter;
	
	for(ucCharacterCounter = 0 ; pcSource[ucCharacterCounter] != NULL ; ucCharacterCounter++)
	{
		pcDestination[ucCharacterCounter] = pcSource[ucCharacterCounter];
	}	
	
	pcDestination[ucCharacterCounter] = NULL;
	
}

enum CompResult { DIFFERENT, EQUAL };

enum CompResult eCompareString(char pcStr1[], char pcStr2[])
{
	unsigned char ucCharacterCounter;
	
	for(ucCharacterCounter = 0 ; pcStr1[ucCharacterCounter] != NULL ; ucCharacterCounter++)
	{
		if(pcStr1[ucCharacterCounter] != pcStr2[ucCharacterCounter])
		{
			return DIFFERENT;
		}
	}
	
	if(pcStr1[ucCharacterCounter] == pcStr2[ucCharacterCounter])
	{
		return EQUAL;
	}
	else
	{
		return DIFFERENT;
	}
}
	
void AppendString(char pcSourceStr[], char pcDestinationStr[])
{
	unsigned char ucCharacterCounter;
	
	for(ucCharacterCounter = 0 ; pcDestinationStr[ucCharacterCounter] != NULL ; ucCharacterCounter++) {}
	
	CopyString(pcSourceStr , pcDestinationStr + ucCharacterCounter);
}

void ReplaceCharactersInString(char pcString[],char cOldChar,char cNewChar)
{
	unsigned char ucCharacterCounter;
	
	for(ucCharacterCounter = 0 ; pcString[ucCharacterCounter] !=NULL ; ucCharacterCounter++)
	{
		if(pcString[ucCharacterCounter] == cOldChar)
			pcString[ucCharacterCounter] = cNewChar; 
	}
}

int main()
{
	//char acSource[] = "teststring";                           //test CopyString
	//char acDestination[MAX_STRING_LENGTH];
	//CopyString(acSource,  acDestination);
	
	//enum CompResult wynik;                                    //test CompResult
	//wynik = eCompareString("kocham", "programowac");
	
	char acSource[] = "teststring";                           //test Appendstring
	char acDestination[MAX_STRING_LENGTH] ="qwerty";
	AppendString(acSource, acDestination);
	
	//char acSource[] = "teststring";
	//ReplaceCharactersInString(acSource, 't', 'a');            //test ReplaceCharactersInString
	
	return 0;
}
