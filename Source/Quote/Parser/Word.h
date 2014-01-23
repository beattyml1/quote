class Word
{
	public: // Constructors
		Word(ICharStream* stream);
		
	public: // Methods
		Word* ParseNext(ICharStream stream);
		Word* AddNext(WordType type, string content);
	
	public: // Properties - Get
		string 		 Content();
		WordType 	 Type();
		Word*		 Next();
		Word*		 Previous();
		ICharStream* Stream();
	
	private: // Constructors
		Word(Word* previous);
		
	private: // Methods
		void Parse();
		
	private: // Variables
		string 			_content;
		WordType 		_type;
		ICharStream* 	_stream;
}