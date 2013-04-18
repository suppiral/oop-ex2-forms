// range validator checks if the value is in range

#pragma once

#include "Validator.h"
#include "Configuration.h"

template <class T>
class RangeValidator: public Validator<T> {
public:
	// constructor: gets upper and lower limits
	RangeValidator(int lower_lim, int upper_lim) : _lower_limit(lower_lim), _upper_limit(upper_lim) { }

	// checks if t is in range
	virtual bool validate(const T& t) const {
		return (_lower_limit <= t && t <= _upper_limit);
	}

	// prints error if there's one.
	virtual ostream& printErr(ostream& os, const T& t) const {
		if (!validate(t))
			os << "Out of range";
		return os;
	}

private:
	int _lower_limit;
	int _upper_limit;
};