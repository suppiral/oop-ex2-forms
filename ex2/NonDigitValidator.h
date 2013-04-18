// NonDigitValidator class checks if a string contains digits.

#pragma once 

#include "Validator.h"
#include "Configuration.h"

class NonDigitValidator : public Validator<string> {
public:
	virtual bool validate(const string& str) const;
	virtual ostream& printErr(ostream& os, const string& str) const;

};


