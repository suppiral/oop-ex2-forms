# pragma once
#include "Validator.h"

class IDValidator:public Validator{
public:
	IDValidator();
	virtual bool validate();

};