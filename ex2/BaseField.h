#pragma once

#include "Configuration.h"
#include "Validator.h"

class BaseField 
{
public:
	BaseField(const string& str);
	
	virtual bool validate() const = 0;
	virtual ostream& print(ostream& os) const = 0;
	ostream& printQuestion(ostream& os) const;
	virtual void fillField() = 0;
	virtual bool isCorrect() const = 0;
	virtual void setIncorrect() = 0;

private:
	string _question;
};

ostream& operator<<(ostream& os, const BaseField& field);