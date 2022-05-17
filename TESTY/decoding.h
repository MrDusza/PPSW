#define NULL '\0'
#define MAX_TOKEN_NR 3
#define MAX_KEYWORD_STRING_LTH 10
#define MAX_KEYWORD_NR 3

enum KeywordCode {LD, ST, RST};
enum TokenType {KEYWORD, NUMBER, STRING};

extern unsigned char ucTokenNr;

union TokenValue
{
	enum KeywordCode eKeyword;
	unsigned int uiNumber;
	char *pcString;
};

struct Token
{
	enum TokenType eType;
	union TokenValue uValue;
};

extern struct Token asToken[MAX_TOKEN_NR];

enum State { TOKEN, DELIMITTER };

unsigned char ucFindTokensInString (char *pcString);
enum Result eStringToKeyword (char pcStr[], enum KeywordCode *peKeywordCode);
void DecodeTokens(void);
void DecodeMsg(char *pcString);
