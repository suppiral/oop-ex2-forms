# pragma once 
#include "Validator.h"
#include "Configuration.h"

class NonDigitValidator : public Validator<string> {
public:
	virtual bool validate(const string& str) const;

};


