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
		case '{': 
		case '[': 
		case '(': 
			FolderOpen();
			break;
		case '}': 	
		case ']':	
		case ')':
			FolderClose();
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

void Word::ParseSpace()
{
	while (_stream.HasMore() and IsWhiteSpace(_stream.Peek()))
	{
		_stream.Pop();
	}
}

void Word::FolderAction()
{
	qchar open = _stream.Pop();
	qchar close;
	
	switch(open)
	{
		case '{': 
			_type = WordType.ContentOpen;
			_close = '}';
			break;
		case '[': 
			_type = WordType.ParamOpen;
			_close = '}';
			break;
		case '(':
			_type = WordType.GroupOpen;
			_close = '}'; 
			break;
	}
	
	_folderRoot = folderItem = new Word();
	_folderRoot->_folderParent;
	_folderRoot->Parse();
	 
	while (folder = folder->ParseNext());
	
	qchar close = _stream.Pop();
	
	if (close != _close)
	{
		_compilerError.Log(String() + "Mismatching folder open and close type. Expected '" + _close + "' and encountered '" + close +"'")
	}
}


