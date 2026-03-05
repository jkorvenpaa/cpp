#include "Form.hpp"

Form::Form(): _name("name"),_signed(false), _gradeToSign(1), _gradeToExecute(1){

}

Form::~Form()
{
}

Form::Form(const Form &other):_name(other._name),_signed(other._signed),
_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){

}

Form &Form::operator=(const Form &other){
	if (this != &other){

	}

}
