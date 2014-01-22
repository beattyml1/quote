class Element
{
		vector<ElementList> InsantiatedParentAttributes;
		vector<ElementList> AttributeTemplates;
		ElementList Content;
		
		vector<Element*> Tags;
		Element* Macro;
		Element* SelectorParent
		vector<Element*> InheritanceParent;
}

typedef ElementList Element* // A pointer to the first element in the list