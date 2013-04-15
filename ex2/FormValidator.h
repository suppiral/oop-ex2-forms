#pragma once
#include "Configuration.h"

class FormValidator {
public:
	virtual bool validate() const = 0;
};