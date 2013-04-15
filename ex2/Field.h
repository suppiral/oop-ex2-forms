#pragma once

#include "Configuration.h"
#include "Validator.h"
#include "BaseField.h"



template <class T>
class Field : public BaseField 
{
public:
	Field(const string& str) : _question(str) { }

	virtual bool validate() {
		for (unsigned i = 0; i < _validators.size(); i++)
			if (!_validator[i]->validate())
				return false;
		return true;
	}

	virtual void print(ostream& os) const {
		printQuestion(os);
		os << " = " << _value << endl;
	}
	
	virtual void fillField() {
		printQuestion(cout);
		cout << endl;
		cin >> _value;
	}


private:
	T _value;
};
