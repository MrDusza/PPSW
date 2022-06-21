#include <LPC21xx.H>
#include "strings.h"
#include "decoding.h"

struct Token asToken[MAX_TOKEN_NR];

struct Keyword
{
	enum KeywordCode eCode;
	char cString[MAX_KEYWORD_STRING_LTH + 1];
};

struct Keyword asKeywordList[MAX_KEYWORD_NR]=
{
	{CAL,"callib"},
	{GT, "goto" },
	{SH, "shift"}
	
};

unsigned char ucTokenNr;

unsigned char ucFindTokensInString(char *pcString)
{
	unsigned char ucCharacterCounter;

	unsigned char ucCurrentCharacter;
	unsigned char ucTokenNumber = 0;
	enum State eState = DELIMITTER;
	
	
	for(ucCharacterCounter = 0 ; ; ucCharacterCounter++)
	{
		ucCurrentCharacter = pcString[ucCharacterCounter];
		
		switch(eState)
		{
			case TOKEN:
			{
				if(ucTokenNumber == MAX_TOKEN_NR)
				{
					return ucTokenNumber;
				}
				else if(ucCurrentCharacter == NULL)
				{
					return ucTokenNumber;
				}
				else if(ucCurrentCharacter != ' ')
				{
					eState = TOKEN;
				}
				else
				{
					eState = DELIMITTER;
				}
				break;
			}
			case DELIMITTER:
			{
				if(ucCurrentCharacter == NULL)
				{
					return ucTokenNumber;
				}
				else if(ucCurrentCharacter == ' ')
				{
					eState = DELIMITTER;
				}
				else
				{
					eState = TOKEN;
					asToken[ucTokenNumber].uValue.pcString = pcString + ucCharacterCounter;
					ucTokenNumber++;
				}
				break;
			}
		}
	}
}

enum Result eStringToKeyword (char pcStr[], enum KeywordCode *peKeywordCode)
{
	unsigned char ucKeywordCounter;
	
	for(ucKeywordCounter = 0 ; ucKeywordCounter < MAX_KEYWORD_NR ; ucKeywordCounter++)
	{
		if(EQUAL == eCompareString(asKeywordList[ucKeywordCounter].cString, pcStr))
		{
			*peKeywordCode = asKeywordList[ucKeywordCounter].eCode;
			return OK;
		}
	}
	return ERROR;
}

void DecodeTokens(void)
{
	unsigned char ucTokenCounter;
	struct Token *psCurrentToken;
	unsigned int uiTokenValue;
	enum KeywordCode eTokenCode;
	
	for(ucTokenCounter = 0 ; ucTokenCounter < ucTokenNr ; ucTokenCounter++)
	{
		psCurrentToken = &asToken[ucTokenCounter];
		
		if(OK == eHexStringToUInt(psCurrentToken -> uValue.pcString, &uiTokenValue))
		{
			psCurrentToken -> eType = NUMBER;
			psCurrentToken -> uValue.uiNumber = uiTokenValue;
		}
		else if(OK == eStringToKeyword(psCurrentToken -> uValue.pcString, &eTokenCode))
		{
			psCurrentToken -> eType = KEYWORD;
			psCurrentToken -> uValue.eKeyword = eTokenCode;
		}
		else
		{
			psCurrentToken -> eType = STRING;
		}
	}
}

void DecodeMsg(char *pcString)
{
	ucTokenNr = ucFindTokensInString(pcString);
	ReplaceCharactersInString(pcString, ' ', NULL);
	DecodeTokens();
}
