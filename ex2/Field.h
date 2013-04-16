#pragma once

#include "Configuration.h"
#include "Validator.h"
#include "BaseField.h"



template <class T>
class Field : public BaseField 
{
public:
	Field(const string& str) : BaseField(str), _isCorrect(false) { }

	virtual bool validate() const {
		for (unsigned i = 0; i < _validators.size(); i++)
			if (!_validators[i]->validate(getValue()))
				return false;
		return true;
	}

	virtual ostream& print(ostream& os) const {
		printQuestion(os);
		os << " = " << _value;
		// print errors (if any)
		for (unsigned i = 0; i < _validators.size(); i++)
		{
			os << "      ";
			_validators[i]->printErr(os, _value);
			os << "      ";
		}
		
		return os;
	}
	
	virtual void fillField() {
		printQuestion(cout);
		cout << endl;
		cin >> _value;
		
		_isCorrect = validate();
	}

	virtual bool isCorrect() const {
		return _isCorrect;
	}

	void addValidator(Validator<T>* validator) { _validators.push_back(validator); }

	const T& getValue() const {
		return _value;
	}

	virtual void setIncorrect() {
		_isCorrect = false;
	}

private:
	T _value;
	vector<Validator<T>*> _validators;
	bool _isCorrect;
};
