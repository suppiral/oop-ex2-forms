//this is the header file for AgeYearValidator class. 
#pragma once
#include "FormValidator.h"
#include "Field.h"
#include <ctime>

template < class T1, class T2 >
class AgeYearValidator : public FormValidator {
public:
	AgeYearValidator(const Field<double>& age, const Field<int>& year) : _ageField(age), _yearField(year) {}
	virtual bool validate() const {


// CHECK IT LATER
/*		time_t curTime = time(NULL);
		tm *tmData = localtime(curTime);
		int year = tmData->tm_year + 1900;

		return (year + int(_ageField.getValue()) == _yearField.getValue() &&  year + int(_ageField.getValue()) +1 == _yearField.getValue());
*/
		return true;
	}
	const Field<double>& _ageField;
	const Field<int>& _yearField;
};
