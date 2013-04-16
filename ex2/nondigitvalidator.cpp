#include "NonDigitValidator.h"
#include <cctype>


/// note to self: put it in a cpp file
bool NonDigitValidator::validate(const string& str) const 
{
	if (str.size() == 0)
		return false;
	for (unsigned i = 0; i < str.size(); i++)
		if (isdigit(str[i]))
			return false;
	return true; 
}

ostream& NonDigitValidator::printErr(ostream& os, const string& str) const 
{
	if (!validate(str))
		os << "Can't contain digits";
	return os;
}