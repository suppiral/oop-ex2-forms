//this is the header file for AgeYearValidator class. 
#pragma once
#include "Validator.h"
#include "Field.h"

template < class T1, class T2 >
class AgeYearValidator: public Validator{
public:
	AgeYearValidator(const T1&, const T2&);
	virtual bool validate();

};
