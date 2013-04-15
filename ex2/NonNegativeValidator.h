#pragma once

#include "Validator.h"

template <class T>
class NonNegativeValidator:public Validator{
public:
	NonNegativeValidator();
	virtual bool validate();

};