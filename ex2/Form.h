#pragma once

#include "Configuration.h"
#include "BaseField.h"
#include "FormValidator.h"

class Form {
public:
	void addField(BaseField* field);
	void addValidator(FormValidator* validator);
	void fillForm();
	bool validateForm() const;

	void printForm(ostream& os) const;

private:
	vector<BaseField*> _fields;
	vector<FormValidator*> _validators;
};

ostream& operator<<(ostream& os, const Form& form);