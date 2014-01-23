class Element
{
	public: // Propeties - Get
		string 				Name();
		vector<Element*> 	Tags();
		Element* 			Macro();
		Element* 			SelectorParent();
		vector<Element*> 	InheritanceParent();
		Word* 				WordLink();
		vector<ElementList> InsantiatedParentAttributes();
		vector<ElementList> AttributeTemplates();
		ElementList 		Content();
}

typedef ElementList Element* // A pointer to the first element in the list