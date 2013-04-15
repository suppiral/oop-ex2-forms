# pragma once 
#include "Validator.h"

class NonDigitValidator: public Validator{
public:
	NonDigitValidator();
	virtual bool validate() { return true; } ; 

};