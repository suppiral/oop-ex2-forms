#pragma once

#include "Configuration.h"
#include "Validator.h"

class BaseField 
{
public:
	BaseField(const string& str);
	void addValidator(Validator* validator);
	virtual bool validate() = 0;
	virtual void print(ostream& os) const = 0;
	void printQuestion(ostream& os) const;
	virtual void fillField();

private:
	vector<Validator*> _validators;
	string _question;
};

ostream& operator<<(ostream& os, const BaseField& field);