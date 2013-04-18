#include "Configuration.h"

// A class to represent a form. A form has many fields
#include "Form.h"

// A class to represent a field. A field can have one validator or more
#include "Field.h"

// A class to represent a range validator. Validates if a field value is in some range.
// Template class must implement < and > operators.
#include "RangeValidator.h"

// A class to represent a no-digit-characters validator. Validates the field value has no digits.
// The template class refers to string only.
#include "NonDigitValidator.h"

// A class to represent an ID validator. A valid ID is checked by the check digit.
// The template class refers to long only.
#include "IDValidator.h"

// A class to represent a Non negative value validator.
// Template class must be able to be > 0;
#include "NonNegativeValidator.h"

// A class to represent a month value.
// The class overrides the << and >> operators
#include "MonthValue.h"

// A class to represent a age vs. year validator. It checks if the age and year supplied fit together.
// The template classes must be Field.
#include "AgeYearValidator.h"	

#include <cstdlib>		// for system()

void clearScreen();
void displayWelcomeMessage();
void displayGoodbyeMessage();
void displayErrorMessage();
void displayFormFields(const Form& toDisplay);

int main()
{
	bool formIsCorrect = false;
	// Creating the form and the fields
	Form myForm;
	Field<double>*     ageField   = new Field<double>    ("What is your age?");
	Field<string>*     nameField  = new Field<string>    ("What is your name?");
	Field<long>*       idField    = new Field<long>      ("What is you ID?");
	Field<int>*        yearField  = new Field<int>       ("What is your birth year?");
	Field<MonthValue>* monthField = new Field<MonthValue>("What is your birth month? (1-12)");

	
	// Creating the field validators
	RangeValidator<double>*     ageValidator   = new RangeValidator<double>(0,120);
	NonDigitValidator*          nameValidator  = new NonDigitValidator;
	IDValidator*                idValidator    = new IDValidator;
	NonNegativeValidator<int>*  yearValidator  = new NonNegativeValidator<int>;
	RangeValidator<MonthValue>* monthValidator = new RangeValidator<MonthValue>(1,12);

	// Adding the validators to the fields
	ageField  ->addValidator(ageValidator);
	nameField ->addValidator(nameValidator);
	idField   ->addValidator(idValidator);
	yearField ->addValidator(yearValidator);
	monthField->addValidator(monthValidator);

	// Creating form validators
	AgeYearValidator<Field<double>, Field<int> >* formValidator = new AgeYearValidator<Field<double>, Field<int> >(*ageField, *yearField);

	// Adding the fields to the form
	myForm.addField(ageField);
	myForm.addField(nameField);
	myForm.addField(idField);
	myForm.addField(yearField);
	myForm.addField(monthField);

	// Adding form validator
	myForm.addValidator(formValidator);

	// Getting the information from the user
	clearScreen();
	displayWelcomeMessage();
	while(true)
	{
		// Get the input only for empty or not valid fields
		myForm.fillForm();

		// Validates all fields
		formIsCorrect = myForm.validateForm();

		// Displays all form fields with value (and error if not valid)
		clearScreen();
		if(!formIsCorrect)
			displayErrorMessage();
		else
			displayGoodbyeMessage();

		displayFormFields(myForm);

		if(formIsCorrect)
			break;
	}

	// Cleanup
	delete ageField;
	delete nameField;
	delete idField;
	delete yearField;
	delete monthField;
	delete ageValidator;
	delete nameValidator;
	delete idValidator;
	delete yearValidator;
	delete monthValidator;
	delete formValidator;

	
	system("pause");
}

void displayFormFields(const Form& toDisplay)
{
	cout << toDisplay << endl;
}

void displayWelcomeMessage()
{
	cout << "+----------------------------------------------------------+" << endl;
	cout << "|                  Hello and welcome                       |" << endl;
	cout << "|  In order to register please fill in the fields below    |" << endl;
	cout << "+----------------------------------------------------------+" << endl;
}

void displayErrorMessage()
{
	cout << "+----------------------------------------------------------+" << endl;
	cout << "|          There was an error in some of the fields!       |" << endl;
	cout << "|                  Please correct them                     |" << endl;
	cout << "+----------------------------------------------------------+" << endl;
}

void displayGoodbyeMessage()
{
	cout << "+----------------------------------------------------------+" << endl;
	cout << "|                      Thank you!                          |" << endl;
	cout << "|               This is the data you sent:                 |" << endl;
	cout << "+----------------------------------------------------------+" << endl;
}

void clearScreen()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}



