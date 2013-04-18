// month value type source

#include "MonthValue.h"

// prints the month's name
ostream& operator<<(ostream& os, const MonthValue& month)
{
	switch (month.getValue()) 
	{
	case January:
		os << "January";
		break;
	case February:
		os << "February";
		break;
	case March:
		os << "March";
		break;
	case April:
		os << "April";
		break;
	case May:
		os << "May";
		break;
	case June:
		os << "June";
		break;
	case July:
		os << "July";
		break;
	case August:
		os << "August";
		break;
	case September:
		os << "September";
		break;
	case October:
		os << "October";
		break;
	case November:
		os << "November";
		break;
	case December:
		os << "December";
		break;
	default:
		os << month.getValue();
		break;
	}
	return os;
}

// read month value from input stream
istream& operator>>(istream& is, MonthValue& month)
{
	is >> month._value;
	return is;
}