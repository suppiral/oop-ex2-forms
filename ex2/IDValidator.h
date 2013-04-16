# pragma once
#include "Validator.h"
#include "Configuration.h"

class IDValidator : public Validator<long> {
public:
	virtual bool validate(const long& id) const; 
	virtual ostream& printErr(ostream& os, const long& id) const;
};

