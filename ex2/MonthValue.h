// month value type.

#pragma once

#include "Configuration.h"

enum MONTH {
	January = 1,
	February = 2,
	March = 3,
	April = 4,
	May = 5,
	June = 6,
	July = 7,
	August = 8,
	September = 9,
	October = 10,
	November = 11,
	December = 12
};




class MonthValue{
public:
	friend istream& operator>>(istream& is, MonthValue& month);
	int getValue() const { return _value; }
	operator int() const { return _value; }

private:
	int _value;
	
};

ostream& operator<<(ostream& os, const MonthValue& month);
istream& operator>>(istream& is, MonthValue& month);