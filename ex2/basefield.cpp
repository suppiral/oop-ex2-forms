#include "BaseField.h"


ostream& operator<<(ostream& os, const BaseField& field)
{
	field.print(os);
	return os;
}

BaseField::BaseField(const string& str) : _question(str) { }


ostream& BaseField::printQuestion(ostream& os) const 
{
	os << _question; 
	return os;
}