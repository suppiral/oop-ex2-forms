//this is the header file for AgeYearValidator class. 

#pragma once

#include "FormValidator.h"
#include "Field.h"
#include <ctime>

template < class T1, class T2 >
class AgeYearValidator : public FormValidator {
public:
	// constructor
	AgeYearValidator(T1& age, T2& year) : _ageField(age), _yearField(year) {}

	// check if age and year match
	virtual bool validate() const {


// CHECK IT LATER
		time_t curTime = time(NULL);
		tm tmData;
		localtime_s(&tmData, &curTime);
		int year = tmData.tm_year + 1900;

	//	int year = 2013;

		if (_yearField.getValue() + _ageField.getValue() == year || _yearField.getValue() + _ageField.getValue() +1 == year)
			return true;

		// else: 

		_ageField.setIncorrect();
		_yearField.setIncorrect();

		return false;
	}

	// print error (if there's one)
	virtual ostream& printErr(ostream& os) const {
		if (validate())
			return os;

		os << "Age and year don't match" << endl;
		return os;
	}

private:
	T1& _ageField;
	T2& _yearField;
};
