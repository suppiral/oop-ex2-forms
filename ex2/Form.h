#pragma once

#include "Configuration.h"
#include "BaseField.h"
#include "Validator.h"

class Form {
public:
	Form();
	void addField(BaseField* field);
	void addValidator(Validator* validator);
	void fillForm();
	bool validateForm() const;

	void printForm(ostream& os) const;

private:
	vector<BaseField*> _fields;
	vector<Validator*> _validators;
};

ostream& operator<<(std::ostream& os, const Form& form);