

Word ParseStartContinueWord(ICharStream stream,  WordType type, qchar[] continueChars, int continueCharsLength)
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
	
	while (stream.HasMore() and Contains(continueChars, continueCharsLength, stream.Peek())
	{
		buffer.append(stream.Pop());
	}
	
	Conent = buffer.ToArray();
	ContentLength = buffer.count;
}