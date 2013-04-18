// Non Negative Validators checks if the number is non negatuve..

#pragma once

#include "Validator.h"

template <class T>
class NonNegativeValidator : public Validator<T> {
public:
	// check
	virtual bool validate(const T& t) const {
		return (0 <= t);
	}
	// print error if there's one.
	virtual ostream& printErr(ostream& os, const T& t) const {
		if (!validate(t))
			os << "Must be positive";
		return os;
	}
};