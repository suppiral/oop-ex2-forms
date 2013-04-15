#include "Form.h"


// adds a field to form
void Form::addField(BaseField* field)
{
	_fields.push_back(field);
}

// adds a validator to form
void Form::addValidator(Validator* validator)
{
	_validators.push_back(validator);
}

bool Form::validateForm() const
{
	// check fields
	for (unsigned i = 0; i < _fields.size(); i++)
		if (!_fields[i]->validate())
			return false;

	// check validators
	for (unsigned i = 0; i < _validators.size(); i++)
		if (!_validators[i]->validate())
			return false;

	return true;
}

void Form::printForm(ostream& os) const
{
	for (unsigned i = 0; i < _fields.size(); i++)
		os << _fields[i];

}

void Form::fillForm()
{
	for (unsigned i = 0; i < _fields.size(); i++)
		_fields[i]->fillField();

}




ostream& operator<<(ostream& os, const Form& form)
{
	form.printForm(os);
}