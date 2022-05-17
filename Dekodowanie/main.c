#include "strings.h"
#include "decoding.h"

char pcString[] = "reset 0xFFFF sklep";

int main()
{
	DecodeMsg(pcString);
	return 0;
}
