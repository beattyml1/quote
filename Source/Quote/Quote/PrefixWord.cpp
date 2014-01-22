
ParsePrefixWord(ICharStream stream)
{
	qchar prefixChar;
	int level = 1;
	
	prefixChar = stream.Pop();
	
	while (stream.HasMore() && stream.Peek() == prefixChar)
	{	
		stream.Pop();
		level++;
	}
	
	switch (prefixChar)
	{
		case '@':
			WordType = WordType.Macro;
			break;
		case '#':
			WordType = WordType.Tag;
			break;
	}
	
	WordType += level;
	
	if (level == 1)
	{
		ParseStartContinueWord(stream, true);
	}
}