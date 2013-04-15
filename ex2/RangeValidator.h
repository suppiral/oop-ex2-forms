#pragma once
#include "Validator.h"
#include "Configuration.h"

template <class T>
class RangeValidator: public Validator<T> {
public:
	RangeValidator(int lower_lim, int upper_lim) : _lower_limit(lower_lim), _upper_limit(upper_lim) { }
	virtual bool validate(const T& t) const {
		return (_lower_limit <= t && t <= _upper_limit);
	}

private:
	int _lower_limit;
	int _upper_limit;
};