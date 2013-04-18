// basefield class source file.

#include "BaseField.h"

// for print
ostream& operator<<(ostream& os, const BaseField& field)
{
	field.print(os);
	return os;
}

// constructor. gets a question
BaseField::BaseField(const string& str) : _question(str) { }

// print question
ostream& BaseField::printQuestion(ostream& os) const 
{
	os << _question; 
	return os;
}