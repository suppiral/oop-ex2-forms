//this is the header file for Validator class 

#pragma once 

#include "Configuration.h"


template <class T>
class Validator {
public:
	virtual bool validate(const T& t) const = 0;
	virtual ostream& printErr(ostream& os, const T& t) const = 0;
};