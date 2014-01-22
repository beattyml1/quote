class Element
{
		vector<ElementList> InsantiatedParentAttributes;
		vector<ElementList> AttributeTemplates;
		ElementList Content;
		
		vector<string> Tags;
		string Macro;
		list<string> ThisSelector
		list<string> ParentSelector;
}

typedef ElementList Element*