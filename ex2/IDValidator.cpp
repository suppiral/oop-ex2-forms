#include "IDValidator.h"
#include <sstream>

using std::stringstream;

const int id_length = 9;

/// note to self: should be in a cpp file
bool IDValidator::validate(const long& id_num) const
{
	// algorithm...

	stringstream str;
	str << id_num;
	string id;
	str >> id;

	if (id.length() != id_length)
		return false;

	int sum = 0;
	for (unsigned i = 0; i < id.length(); i++)
	{
		char c;
		c = id[i];
		int digit = atoi(&c);

		if (i%2 == 0)
			sum += digit;
		else
		{
			sum += (2*digit)%10;
			sum += (2*digit)/10;
		}
	}
			
	if (sum%10 == 0)
		return true;
	return false;
}

// print error
ostream& IDValidator::printErr(ostream& os, const long& id) const 
{
	if (!validate(id))
		os << "Wrong check digit";
	return os;
}