#include "IDValidator.h"


/// note to self: should be in a cpp file
bool IDValidator::validate(const long& id) const
{
	// algorithm...
	if (id > 0)
		return true;
	return false;
}

ostream& IDValidator::printErr(ostream& os, const long& id) const 
{
	if (!validate(id))
		os << "Wrong check digit";
	return os;
}