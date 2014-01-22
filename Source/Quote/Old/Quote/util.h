
const int WhitespaceCharsLength = 4
const qchar WhitespaceChars[WhitespaceCharsLength] = { ' ', '\n' '\t', '\r' }



static bool Contains(qchar[] chars, int charsLength, qchar c)
{
	for (int i = 0; i < charsLength; i++)
	{
		if (chars[i] == c) return true;
	}
	
	return false;
}

static bool IsWhiteSpace(qchar c const)
{
	return Contains(WhitespaceChars, WhitespaceCharsLength, c);
}

static inline bool IsNameStart(qchar c)
{
	Contains(NameStartChars, NameStartCharsLength, c);
}