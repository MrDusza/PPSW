#include "strings.h"
#include "decoding.h"

char pcString[] = "reset 0xFFFF sklep";

int main()
{
	//ucFindTokensInString(pcString);
	//ReplaceCharactersInString(pcString, ' ', NULL);
	DecodeMsg(pcString);
	return 0;
}
