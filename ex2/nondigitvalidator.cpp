#include "NonDigitValidator.h"
#include <cctype>


/// note to self: put it in a cpp file
bool NonDigitValidator::validate(const string& str) const 
{
	for (unsigned i = 0; i < str.size(); i++)
		if (isdigit(str[i]))
			return false;
	return true; 
}