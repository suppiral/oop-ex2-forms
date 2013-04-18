// Form class source file.

#include "Form.h"

// adds a field to form
void Form::addField(BaseField* field)
{
	_fields.push_back(field);
}

// adds a validator to form
void Form::addValidator(FormValidator* validator)
{
	_validators.push_back(validator);
}

// checks if the form is valid
bool Form::validateForm() const
{
	// check fields
	for (unsigned i = 0; i < _fields.size(); i++)
		if (!_fields[i]->isCorrect())
			return false;

	// check validators
	for (unsigned i = 0; i < _validators.size(); i++)
		if (!_validators[i]->validate())
			return false;

	return true;
}

// prints the form
void Form::printForm(ostream& os) const
{
	for (unsigned i = 0; i < _fields.size(); i++)
	{
		os << "------------------------------------------------------------" << endl;
		_fields[i]->print(os);
		os << endl;
		os << "------------------------------------------------------------" << endl;
	}

	for (unsigned i = 0; i < _validators.size(); i++)
			_validators[i]->printErr(os);

}

void Form::fillForm()
{
	for (unsigned i = 0; i < _fields.size(); i++)
		if (!_fields[i]->isCorrect())
			_fields[i]->fillField();

}




ostream& operator<<(ostream& os, const Form& form)
{
	form.printForm(os);
	return os;
}