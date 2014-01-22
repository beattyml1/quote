Parse(ICharStream stream)
{
	qchar first = stream.Peek();
	
	switch (first)
	{
		case '@':
		case '#':
			ParsePrefixWord(stream);
			break;
		case '"':
		case '\'':
			ParseString(stream);
			break;
		case ',':
		case ';': 
			ParseSeperator(stream);
		case '`':
		case '~':
			ParseComment(stream);
			break;
		case ':':
			ParseDeclaration(stream);
			break;
		case '.':
			ParseMembership(stream);
			break;
		case '{': case '}' 
		case '[': case ']'
		case '(': case ')':
			FolderAction(stream);
			break;
		default:
			if (IsSpace(first)
				ParseSpace(stream);
			if (IsSymbolic(first))
				ParseSymbolic(stream)
			else
			{
				if (IsNameStart(stream.Peek()))
					ParseStartContinue(stream, Type = Name, NameContinueChars, NameContinueCharsLength);
				else 
					ParseStartContinue(stream, Type = Name, NumericContinueChars, NumericContinueCharsLength);
					
			}
	}
}

void ParseSpace(ICharStream stream)
{
	while (stream.HasMore() and IsWhiteSpace(stream.Peek()))
	{
		stream.Pop();
	}
}