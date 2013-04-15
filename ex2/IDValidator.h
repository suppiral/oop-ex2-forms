# pragma once
#include "Validator.h"
#include "Configuration.h"

class IDValidator : public Validator<long> {
public:
	virtual bool validate(const long& id) const; 

};


/// note to self: should be in a cpp file
bool IDValidator::validate(const long& id) const
{
	// algorithm...
	return true;
}