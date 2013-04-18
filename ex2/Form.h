// Form class. a form contains fields and validators of fields.

#pragma once

#include "Configuration.h"
#include "BaseField.h"
#include "FormValidator.h"

class Form {
public:
	void addField(BaseField* field);			  // add a field to form
	void addValidator(FormValidator* validator); // add a validator of fields
	void fillForm();							// fills the form
	bool validateForm() const;				   // check if the form is ok
	void printForm(ostream& os) const;		  // prints the form

private:
	vector<BaseField*> _fields;
	vector<FormValidator*> _validators;
};

ostream& operator<<(ostream& os, const Form& form);