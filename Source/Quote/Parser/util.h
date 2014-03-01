
const int WhitespaceCharsLength = 4
const qchar WhitespaceChars[WhitespaceCharsLength] = { ' ', '\n' '\t', '\r' }

static bool Contains(qchar[] chars, int charsLength, qchar c);

static bool IsWhiteSpace(qchar c const);

static inline bool IsNameStart(qchar c);