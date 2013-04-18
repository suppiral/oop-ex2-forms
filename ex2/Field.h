// template field class. storing the value, question and validators.

#pragma once

#include "Configuration.h"
#include "Validator.h"
#include "BaseField.h"

template <class T>
class Field : public BaseField 
{
public:
	// constructor
	Field(const string& str) : BaseField(str), _isCorrect(false) { }

	// validates the value in the field.
	virtual bool validate() const {
		// check each validator
		for (unsigned i = 0; i < _validators.size(); i++)
			if (!_validators[i]->validate(getValue()))
				return false;
		return true;
	}

	// print the question, the value and validator output
	virtual ostream& print(ostream& os) const {
		printQuestion(os);
		os << " = " << getValue();
		// print errors (if any)
		for (unsigned i = 0; i < _validators.size(); i++)
		{
			os << "      ";
			_validators[i]->printErr(os, getValue());
			os << "      ";
		}
		
		return os;
	}
	
	// ask a question and get an answer
	virtual void fillField() {
		printQuestion(cout);
		cout << endl;
		cin >> _value;
		
		// validate the value
		_isCorrect = validate();
	}

	// is the field correct?
	virtual bool isCorrect() const {
		return _isCorrect;
	}

	// add a validator to field
	void addValidator(Validator<T>* validator) { _validators.push_back(validator); }

	// return the value
	const T& getValue() const {
		return _value;
	}

	// set field as incorrect
	virtual void setIncorrect() {
		_isCorrect = false;
	}

private:
	// the value
	T _value;
	// validators
	vector<Validator<T>*> _validators;
	// is the field correct?
	bool _isCorrect;
};
