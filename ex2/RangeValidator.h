#pragma once
#include "Validator.h"

template <class T>
class RangeValidator: public Validator {
public:
	RangeValidator(int, int);
	virtual bool validate(); 

private:

};