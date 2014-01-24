class ISource
{
	public: // Properties - Get
		qchar 	Pop();
		qchar 	Peep();
		void 	PutBack(qchar c);
		bool 	HasMore();
		int 	LineNumber();
		int		CharNumber(); 
		SourceInfo* Info();
		
	public: // Methods	
		void	IncrementLineNumber(int ammount = 1);
};