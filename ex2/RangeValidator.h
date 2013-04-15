#pragma once
#include "Validator.h"

class RangeValidator: public Validator {
public:
	RangeValidator(int, int);
	virtual bool validate(); 

private:

};