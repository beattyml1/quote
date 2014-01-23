Word* Word::Parse(ICharStream _stream)
{
	qchar first = _stream.Peek();
	
	switch (first)
	{
		case '@':
		case '#':
			ParsePrefixWord(_stream);
			break;
		case '"':
		case '\'':
			ParseString(_stream);
			break;
		case ',':
		case ';': 
			ParseSeperator(_stream);
		case '`':
		case '~':
			ParseComment(_stream);
			break;
		case ':':
			ParseDeclaration(_stream);
			break;
		case '.':
			ParseMembership(_stream);
			break;
		case '{': case '}' 
		case '[': case ']'
		case '(': case ')':
			FolderAction(_stream);
			break;
		default:
			if (IsSpace(first)
				ParseSpace(_stream);
			if (IsSymbolic(first))
				ParseSymbolic(_stream)
			else
			{
				if (IsNameStart(_stream.Peek()))
					ParseStartContinue(_stream, _type = Name, NameContinueChars, NameContinueCharsLength);
				else 
					ParseStartContinue(_stream, _type = Numeric, NumericContinueChars, NumericContinueCharsLength);
					
			}
	}
}

void Word::ParseSpace(ICharStream _stream)
{
	while (_stream.HasMore() and IsWhiteSpace(_stream.Peek()))
	{
		_stream.Pop();
	}
}

Word*
