#pragma once

#include "Validator.h"

template <class T>
class NonNegativeValidator : public Validator<T> {
public:
	virtual bool validate(const T& t) const {
		return t < 0;
	}

};