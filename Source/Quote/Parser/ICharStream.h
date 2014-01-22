class ICharStream
{
	public:
		qchar Pop();
		qchar Peep();
		void PutBack(qchar c);
		bool HasMore();
};