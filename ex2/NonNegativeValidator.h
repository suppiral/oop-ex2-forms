#pragma once

#include "Validator.h"

template <class T>
class NonNegativeValidator : public Validator<T> {
public:
	virtual bool validate(const T& t) const {
		return (0 <= t);
	}
	virtual ostream& printErr(ostream& os, const T& t) const {
		if (!validate(t))
			os << "Must be positive";
		return os;
	}
};