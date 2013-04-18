// Form validator for Form class. base class used for polymorphism

#pragma once
#include "Configuration.h"

class FormValidator {
public:
	virtual bool validate() const = 0;
	virtual ostream& printErr(ostream& os) const = 0;
};