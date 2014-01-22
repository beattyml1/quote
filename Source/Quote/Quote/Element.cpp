void Element::Parse(ICharStream& stream)
{
	while (stream.HasMore())
	{
		ProcessNextWord(Word(stream));
	}
}

void Element::ProcessNextWord(Word word)
{
	switch (word.Type)
	{
		case Macro:
			break;
		case Name:
			break;
		case Numeric:
			break;
		case Symbolic:
			break;
		case Tag:
			break;
		case FolderAction:
			break;
	}
}

void Element::CreateNextElement(Word& word, ICharStream& steam)
{
	_next = new Element();
	_next.ProcessNextWord(word);
	_next.Parse(stream);
}
