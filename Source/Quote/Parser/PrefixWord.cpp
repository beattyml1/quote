
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
			_type = WordType.Macro;
			break;
		case '#':
			_type = WordType.Tag;
			break;
	}
	
	_type += level;
	
	if (level == 1)
	{
		ParseStartContinueWord(Name, NameContinueChars, NameContinueCharsLength);
	}
}