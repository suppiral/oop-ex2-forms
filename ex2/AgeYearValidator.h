//this is the header file for AgeYearValidator class. 
#pragma once
#include "FormValidator.h"
#include "Field.h"
#include <ctime>

template < class T1, class T2 >
class AgeYearValidator : public FormValidator {
public:
	AgeYearValidator(T1& age, T2& year) : _ageField(age), _yearField(year) {}
	virtual bool validate() const {


// CHECK IT LATER
/*		time_t curTime = time(NULL);
		tm *tmData = localtime(curTime);
		int year = tmData->tm_year + 1900;
*/
		int year = 2013;

		if (_yearField.getValue() + int(_ageField.getValue()) == year || _yearField.getValue() + int(_ageField.getValue()) +1 == year)
			return true;

		// else: 

		_ageField.setIncorrect();
		_yearField.setIncorrect();

		return false;
	}

	virtual ostream& printErr(ostream& os) const {
		if (validate())
			return os;

		os << "Age and year don't match" << endl;
		return os;
	}


	T1& _ageField;
	T2& _yearField;
};
