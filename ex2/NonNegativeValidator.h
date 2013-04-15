#pragma once

#include "Validator.h"

class NonNegativeValidator : public Validator {
public:
	NonNegativeValidator();
	virtual bool validate();

};