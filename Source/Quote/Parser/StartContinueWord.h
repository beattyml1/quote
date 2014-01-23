

void Word::ParseStartContinueWord(WordType type, qchar[] continueChars, int continueCharsLength)
{
	if (type == Name) 
	{
		continueCharsLength = NameContinueCharsLength;
		continueChars = NameContinueChars;
	}
	else
	{
		continueCharsLength = NumericContinueCharsLength;
		continueChars = NumericContinueChars;
	}
	
	list<qchar> buffer;
	
	while (_stream.HasMore() and Contains(continueChars, continueCharsLength, _stream.Peek())
	{
		buffer.append(_stream.Pop());
	}
	
	_content = ToString(buffer);
}