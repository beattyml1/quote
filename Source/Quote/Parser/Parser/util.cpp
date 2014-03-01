//
//  util.cpp
//  Parser
//
//  Created by Matthew Beatty on 3/1/14.
//  Copyright (c) 2014 Matthew Beatty. All rights reserved.
//

#include "../Interface/util.h"

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