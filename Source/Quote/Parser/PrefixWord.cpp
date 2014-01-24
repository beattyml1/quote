
void Word::ParsePrefixWord()
{
	qchar prefixChar;
	int level = 1;
	
	prefixChar = _stream.Pop();
	
	while (_stream.HasMore() && _stream.Peek() == prefixChar)
	{	
		_stream.Pop();
		level++;
	}
	
	switch (prefixChar)
	{
		case '@':
			_type = MACRO;
			break;
		case '#':
			_type = TAG;
			break;
		case '?': 
			_type = QUERY_SIMPLE;
			break;
	}
	
	_type += level;
	
	if (level == 1)
	{
		ParseStartContinueWord(Name, NameContinueChars, NameContinueCharsLength);
	}
	else
	{
		ProcessStartEndWord(prefixChar, level);
	}
}

void Word::ProcessStartEndWord(qchar prefixChar, int level)
{
	int openLevel = _parser.State().WrapperLevel(prefixChar); // 0 if not in wrapper otherwise wrapper level
	
	if (openLevel == 0)
	{
		ParseFolderContents();
	}
	else
	{
		if (level != openLevel)
		{
			_parser.Host().ParserErrorLogger().Log(Errors::MismatchStartEnd(prefixChar, level))
		}
		
		ParseNext(); // TODO: Should compiler continue
	}
	
}