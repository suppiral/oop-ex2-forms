#pragma once

#include <iostream>

class MonthValue{


public:
	MonthValue();

private:
	int _value;
	bool operator < ( const MonthValue& );
	bool operator > ( const MonthValue& );
};