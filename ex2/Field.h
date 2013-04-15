#pragma once

#include "Configuration.h"
#include "Validator.h"
#include "BaseField.h"



template <class T>
class Field : public BaseField 
{
public:
	Field(const string& str) : BaseField(str) { }

	virtual bool validate() const {
		for (unsigned i = 0; i < _validators.size(); i++)
			if (!_validators[i]->validate(getValue()))
				return false;
		return true;
	}

	virtual void print(ostream& os) const {
		printQuestion(os);
		os << " = " << _value;
		// print errors (if any)
	/*	for (unsigned i = 0; i < _validators.size(); i++)
		{
			os << "      ";
			_validators[i]->printerr(os);
			os << "      ";
		}
	*/
	}
	
	virtual void fillField() {
		printQuestion(cout);
		cout << endl;
		cin >> _value;
	}

	void addValidator(Validator<T>* validator) { _validators.push_back(validator); }

	const T& getValue() const {
		return _value;
	}


private:
	T _value;
	vector<Validator<T>*> _validators;
};
