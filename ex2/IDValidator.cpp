#include "IDValidator.h"
#include <sstream>

using std::stringstream;

const int id_length = 9;

// id validation algorithm.
bool IDValidator::validate(const long& id_num) const
{
	// we want to be able to pull the id digit after digit so we will convert it to a string
	stringstream str;
	str << id_num;
	string id;
	str >> id;

	// check length of the id
	if (id.length() != id_length)
		return false;

	int sum = 0; // the sum % 10 needs to be 0 at the end.
	// sum all digit.
	for (unsigned i = 0; i < id.length(); i++) 
	{
		char c;
		c = id[i];
		int digit = atoi(&c); // get digit as a number

		if (i%2 == 0) // the digits in the even places will be added to the sum
			sum += digit;
		else // the digits in the odd places will be multiplied by 2 and their digits will be added to the sum.
		{
			sum += (2*digit)%10;
			sum += (2*digit)/10;
		}
	}
			
	// check condition.
	if (sum%10 == 0)
		return true;
	// else:
	return false;
}

// print error
ostream& IDValidator::printErr(ostream& os, const long& id) const 
{
	if (!validate(id))
		os << "Wrong check digit";
	return os;
}