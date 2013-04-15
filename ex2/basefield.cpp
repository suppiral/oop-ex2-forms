#include "BaseField.h"


ostream& operator<<(ostream& os, const BaseField& field)
{
	field.print(os);
}

void BaseField::addValidator(Validator* validator) { _validators.push_back(validator); }

BaseField::BaseField(const string& str) : _question(str) { }


void BaseField::printQuestion(ostream& os) const { os << _question; }