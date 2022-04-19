#include <LPC21xx.H>

#define NULL '\0'
#define MAX_STRING_LENGTH 254

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

enum Result { OK, ERROR };

enum Result eHexStringToUInt(char pcStr[], unsigned int *puiValue)
{
	unsigned char ucNibbleCounter;
	unsigned char ucNibbleCharacter;

	*puiValue = 0;
	
	if (pcStr[0] != '0' | pcStr[1] != 'x' | pcStr[2] == NULL )
	{
		return ERROR;
	}
	
	for(ucNibbleCounter = 2 ; ucNibbleCounter < 7 ; ucNibbleCounter++)
	{
		ucNibbleCharacter = pcStr[ucNibbleCounter];
		
		if (ucNibbleCharacter == NULL)
		{
			return OK;
		}
		
		if (ucNibbleCounter == 6)
		{
			return ERROR;
		}
		
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
}

//char ucaResult[7];
unsigned int uiValue;

int main()
{
	//UIntToHexStr(0xa2c8 , ucaResult);
	
	eHexStringToUInt("0x1111" , &uiValue);

	return 0;
}
