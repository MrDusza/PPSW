#include "strings.h"

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

void UIntToHexStr (unsigned int uiValue, char pcStr[])
{
	unsigned char ucNibbleCounter;
	unsigned char ucNibbleValue;

	pcStr[0] = '0';
	pcStr[1] = 'x';

	for(ucNibbleCounter = 0 ; ucNibbleCounter < 4 ; ucNibbleCounter++)
	{
		ucNibbleValue = (uiValue >> (4 * ucNibbleCounter)) & 0xf;

		if (ucNibbleValue < 10)
		{
			pcStr[5 - ucNibbleCounter] = (ucNibbleValue + '0');
		}
		else
		{
			pcStr[5 - ucNibbleCounter] = (ucNibbleValue + 'A' - 10);
		}
	}

	pcStr[6] = NULL;
}

enum Result eHexStringToUInt(char pcStr[], unsigned int *puiValue)
{
	unsigned char ucNibbleCounter;
	unsigned char ucNibbleCharacter;

	*puiValue = 0;

	if ((pcStr[0] != '0') | (pcStr[1] != 'x') | (pcStr[2] == NULL))
	{
		return ERROR;
	}

	for(ucNibbleCounter = 2 ; pcStr[ucNibbleCounter] != NULL ; ucNibbleCounter++)
	{
		if (ucNibbleCounter == 6)
		{
			return ERROR;
		}

		ucNibbleCharacter = pcStr[ucNibbleCounter];

		*puiValue = *puiValue << 4;

		if ((ucNibbleCharacter >= 'A') && (ucNibbleCharacter <= 'F'))
		{
			*puiValue = *puiValue | (ucNibbleCharacter - 'A' + 10);
		}
		else if ((ucNibbleCharacter >= '0') && (ucNibbleCharacter <= '9'))
		{
			*puiValue = *puiValue | (ucNibbleCharacter - '0');
		}
		else
		{
			return ERROR;
		}
	}
	return OK;
}

void AppendUIntToString (unsigned int uiValue, char pcDestinationStr[])
{
	unsigned char ucLastCharacter;

	for(ucLastCharacter = 0 ; pcDestinationStr[ucLastCharacter] != NULL ; ucLastCharacter++)
	{}

	UIntToHexStr (uiValue, &pcDestinationStr[ucLastCharacter]);
}
