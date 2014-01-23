class Word
{
	public: // Constructors
		Word(ICharStream* stream);
		
	public: // Methods
		Word* ParseNext(ICharStream stream);
		Word* AddNext(WordType type, string content);
		Element* CreateElement();
	
	public: // Properties - Get
		string 		 Content();
		WordType 	 Type();
		Word*		 Next();
		Word*		 Previous();
		ICharStream* Stream();
		Word* 		 FolderRoot();
		Word*		 FolderParent();
		
	private: // Methods
		void Parse();
		void ParseStartContinueWord(WordType type, qchar[] continueChars, int continueCharsLength);
		void ParsePrefixWord();
		void FolderAction();
		void ParseSpace();
		void ParseSeperator();
		
	private: // Variables
		string 			_content;
		WordType 		_type;
		ICharStream* 	_stream;
		Word*			_folderRoot;
		Word*			_folderParent;
		qchar			_close;
}