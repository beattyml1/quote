class Word
{
	public: // Constructors
		Word(ISource* stream);
		
	public: // Methods
		Word* ParseNext();
		Word* AddNext(WordType type, string content);
		Element* CreateElement();
	
	public: // Properties - Get
		string 		 Content();
		WordType 	 Type();
		Word*		 Next();
		Word*		 Previous();
		ISource*     Stream();
		Word* 		 FolderRoot();
		Word*		 FolderParent();
		SourceInfo*  SourceInformation();
		
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
		ISource* 		_stream;
		Word*			_folderRoot;
		Word*			_folderParent;
		qchar			_close;
}