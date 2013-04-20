OOP2 - EX2 - FORMS

Gil Mizrahi: 201634300
Eviatar Levy: 300510658

				General Descriptions:
-------------------------------------------------------------------------------
We were instructed to build a system of Forms where the user is presented with a form: question the user is asked to answer. the form checks the fields validity.

				   Files list:
-------------------------------------------------------------------------------
*) main.cpp & configuration.h: received from the staff.
*) form.h/cpp: form class.
*) basefield.h: abstract base class for field.
*) field.h: template class for field.
*) validator.h: base template class for validators.
*) FormValidator.h: abstract base class for form validators.
*) other validators for fields.


			Main databases and its tasks:
-------------------------------------------------------------------------------
*) each form contains a vector of fields and a vector of form validators
*) each field contains a vector of validators for it's type

				Algorithms:
-------------------------------------------------------------------------------
*) ID validity check.

				Known bugs: 
-------------------------------------------------------------------------------
*) none.
