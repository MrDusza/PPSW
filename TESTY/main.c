#include "strings.h"
#include "decoding.h"
#include <stdio.h>

void TestOf_CopyString()
{
    char cTest_1_Destination[] = "fghij";
    char cTest_2_Destination[] = "fghij";
    char cTest_3_Destination[] = "fghij";

    printf("CopyString\n\n");

    printf("Test 1 - ");
    //stringi tej samej dlugosci
	CopyString("abcde",  cTest_1_Destination);
	if (eCompareString("abcde",  cTest_1_Destination) == EQUAL) printf("OK\n"); else printf("Error\n");

    printf("Test 2 - ");
    //string pierwszy krotszy
	CopyString("abc", cTest_2_Destination);
	if (eCompareString("abc", cTest_2_Destination) == EQUAL) printf("OK\n"); else printf("Error\n");

	printf("Test 3 - ");
	//string pierwszy pusty
    CopyString("", cTest_3_Destination);
    if (eCompareString("", cTest_3_Destination) == EQUAL) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_eCompareString()
{
    printf("eCompareString\n\n");

	printf("Test 1 - ");
	//dwa takie same stringi tej samej dlugosci
	if (eCompareString("abcde", "abcde") == EQUAL) printf("OK\n"); else printf("Error\n");

	printf("Test 2 - ");
	//dwa rozne stringi tej samej dlugosci
	if (eCompareString("abcde", "fghij") == DIFFERENT) printf("OK\n"); else printf("Error\n");

	printf("Test 3 - ");
	//piewszy string pusty
	if (eCompareString("", "fghij") == DIFFERENT) printf("OK\n"); else printf("Error\n");

	printf("Test 4 - ");
	//drugi string pusty
	if (eCompareString("abcde", "") == DIFFERENT) printf("OK\n"); else printf("Error\n");

	printf("Test 5 - ");
	//dwa stringi puste
	if (eCompareString("", "") == EQUAL) printf("OK\n"); else printf("Error\n");

	printf("Test 6 - ");
	//pierwszy string krotrzy od drogiego
	if (eCompareString("abcde", "abcdef") == DIFFERENT) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_AppendString()
{
    char cAppendingTest1[] = "fghij";
    char cAppendingTest2[] = "fghij";
    char cAppendingTest3[] = "";

	printf("AppendString\n\n");

	printf("Test 1 - ");
	//dwa dowolne stringi
	AppendString("abcde", cAppendingTest1);
	if (eCompareString(cAppendingTest1, "fghijabcde") == EQUAL) printf("OK\n"); else printf("Error\n");

	printf("Test 2 - ");
	//pierwszy string pusty
	AppendString("", cAppendingTest2);
	if (eCompareString(cAppendingTest2, "fghij") == EQUAL) printf("OK\n"); else printf("Error\n");

	printf("Test 3 - ");
	//drugi string pusty
	AppendString("abcde", cAppendingTest3);
	if (eCompareString(cAppendingTest3, "abcde") == EQUAL) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_ReplaceCharactersInString()
{
    char cOryginal1[] = "Agata";
    char cOryginal2[] = "Ala ma kota";

	printf("ReplaceCharactersInString\n\n");

	printf("Test 1 - ");
	//zamiana dowolnych znakow
	ReplaceCharactersInString(cOryginal1, 'a', 'A');
	if (eCompareString(cOryginal1, "AgAtA") == EQUAL) printf("OK\n"); else printf("Error\n");

	printf("Test 2 - ");
	//zamiana spacji na NULLe
	ReplaceCharactersInString(cOryginal2, ' ', NULL);
	if (eCompareString(cOryginal2, "Ala\0ma\0kota\0") == EQUAL) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_UIntToHexStr()
{
    char cAfterConverion[6];

	printf("UIntToHexStr\n\n");

	printf("Test 1 - ");
	//krance przedzialow, 0,9,10,15
	UIntToHexStr(0x09af, cAfterConverion);
	if (eCompareString(cAfterConverion, "0x09AF") == EQUAL) printf("OK\n"); else printf("Error\n");

	printf("Test 2 - ");
	//zera po x w incie
	UIntToHexStr(0x34, cAfterConverion);
	if (eCompareString(cAfterConverion, "0x0034") == EQUAL) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_eHexStringToUInt()
{
	enum Result eReturnResult;
	unsigned int uiReturnValue;

	printf("eHexStringToUInt\n\n");

	printf("Test 1 - ");
	//krance przedzialow 0,9,10,15
	eReturnResult = eHexStringToUInt("0x09AF", &uiReturnValue);
	if (eReturnResult == OK) printf("OK\n"); else printf("Error\n");

	printf("Test 2 - ");
	//za krotki string
	eReturnResult = eHexStringToUInt("0x", &uiReturnValue);
	if (eReturnResult == ERROR) printf("OK\n"); else printf("Error\n");

	printf("Test 3 - ");
	//za dlugi string
	eReturnResult = eHexStringToUInt("0xFFDC2", &uiReturnValue);
	if (eReturnResult == ERROR) printf("OK\n"); else printf("Error\n");

	printf("Test 4 - ");
	//poczatek rozny od 0x
	eReturnResult = eHexStringToUInt("klhfcsd", &uiReturnValue);
	if (eReturnResult == ERROR) printf("OK\n"); else printf("Error\n");

	printf("Test 5 - ");
	//mniej znakow w stringu
	eReturnResult = eHexStringToUInt("0x034", &uiReturnValue);
	if (eReturnResult == OK) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_AppendUIntToString()
{
    char cOryginal1[] = "test_text";
    char cOryginal2[] = "";

	printf("AppendUIntToString\n\n");

	printf("Test 1 - ");
	//niepusty string, dopisywanie od NULLa
	AppendUIntToString(0x1234, cOryginal1);
	if (eCompareString(cOryginal1, "test_text0x1234") == EQUAL) printf("OK\n"); else printf("Error\n");

	printf("Test 2 - ");
	//pusty string
	AppendUIntToString(0x1234, cOryginal2);
	if (eCompareString(cOryginal2, "0x1234") == EQUAL) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_ucFindTokensInString()
{
	unsigned char ucTokenNumber;
	char pcTestString[] = "0x3343 ABDC DEFGH reset";

	printf("ucFindTokensInString\n\n");

	printf("Test 1 - ");
	//max liczba tokenow
	ucTokenNumber = ucFindTokensInString("0x3343 ABDCDEFGH reset");
	if (ucTokenNumber == 3) printf("OK\n"); else printf("Error\n");

	printf("Test 2 - ");
	//same delimitery
	ucTokenNumber = ucFindTokensInString("    ");
	if (ucTokenNumber == 0) printf("OK\n"); else printf("Error\n");

	printf("Test 3 - ");
	//delimitery na poczatku stringu, mniej tokenow niz maks
	ucTokenNumber = ucFindTokensInString("   0x3343 ABDCDEFGH ");
	if (ucTokenNumber == 2) printf("OK\n"); else printf("Error\n");

	printf("Test 4 - ");
	//kilka delimiterow pomiedzy tokenami
	ucTokenNumber = ucFindTokensInString("0x3343   ABDCDEFGH      reset");
	if (ucTokenNumber == 3) printf("OK\n"); else printf("Error\n");

	printf("Test 5 - ");
	//za duzo tokenow, (zwraca 3 i ustawia wskazniki na pierwsze 3)
	ucTokenNumber = ucFindTokensInString(pcTestString);
	if ((ucTokenNumber == 3) && (&pcTestString[0] == asToken[0].uValue.pcString)
    && (&pcTestString[7] == asToken[1].uValue.pcString)
    && (&pcTestString[12] == asToken[2].uValue.pcString)) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_eStringToKeyword()
{
	enum KeywordCode eTokenCode;

	printf("eStringToKeyword\n\n");

	printf("Test 1 - ");
	//slowo kluczowe
	if (eStringToKeyword("reset", &eTokenCode) == OK) printf("OK\n"); else printf("Error\n");

	printf("Test 2 - ");
	//brak slowa kluczowego
	if (eStringToKeyword("nie_slowo_klucz", &eTokenCode) == ERROR) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_DecodeTokens()
{
	char pcSource[] = "0x30FA ABDCDEFGH reset";

	printf("DecodeTokens\n\n");

	printf("Test 1 - ");
	//liczba i jej zapis, string i ustawienie wskaznika, keyword i zapis kodu
	ucTokenNr = 3;
	asToken[0].uValue.pcString = &pcSource[0];
    asToken[1].uValue.pcString = &pcSource[7];
    asToken[2].uValue.pcString = &pcSource[17];
    pcSource[6] = NULL;
    pcSource[16] = NULL;

    DecodeTokens();

	if ((asToken[0].eType == NUMBER) && (asToken[0].uValue.uiNumber == 0x30FA) &&
    (asToken[1].eType == STRING) && (asToken[1].uValue.pcString == &pcSource[7]) &&
    (asToken[2].eType == KEYWORD) && (asToken[2].uValue.eKeyword == RST)) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_DecodeMsg()
{
	char pcToDecode[] = "0x30FA ABDCDEFGH reset";

	printf("DecodeMsg\n\n");

	printf("Test 1 - ");
	//dekodowanie liczby, stringa i keyworda
	DecodeMsg(pcToDecode);
	if ((asToken[0].eType==NUMBER) && (asToken[0].uValue.uiNumber==0x30FA) &&
    (asToken[1].eType==STRING) && (&pcToDecode[7]==asToken[1].uValue.pcString) &&
    (asToken[2].eType==KEYWORD) && (asToken[2].uValue.eKeyword==RST)) printf("OK\n\n"); else printf("Error\n\n");
}

int main()
{
    printf("TESTY FUNKCJI - LANCUCHY ZNAKOWE - OPERACJE PROSTE\n\n\n");

	TestOf_CopyString();
	TestOf_eCompareString();
	TestOf_AppendString();
	TestOf_ReplaceCharactersInString();

	printf("TESTY FUNKCJI - LANCUCHY ZNAKOWE - KONWERSJE\n\n\n");

	TestOf_UIntToHexStr();
	TestOf_eHexStringToUInt();
	TestOf_AppendUIntToString();

	printf("TESTY FUNKCJI - DEKODOWANIE KOMUNIKATOW\n\n\n");

    TestOf_ucFindTokensInString();
    TestOf_eStringToKeyword();
    TestOf_DecodeTokens();
    TestOf_DecodeMsg();
}
