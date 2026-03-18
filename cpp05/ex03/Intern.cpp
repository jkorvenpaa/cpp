#include  "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}
Intern::Intern(const Intern &other){
	(void) other;
}

Intern	&Intern::operator=(const Intern &other){
	(void) other;
	return *this;

}
Intern::NoFormException::NoFormException(const std::string &message): _message(message){

}
const char* Intern::NoFormException:: what() const noexcept{
	return _message.c_str();
}

AForm*	Intern::makeForm(const std::string name, const std::string target){

	const std::string type[3]{
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};
	int level = 0;
	for(int i = 0; i < 3; i++){
		if (type[i] == name)
			level = i+1;
	}
	switch(level)
	{
		case 1:
			std::cout << "Intern creates form  " << name << std::endl;
			return new ShrubberyCreationForm(target);
		case 2:
			std::cout << "Intern creates form  " << name << std::endl;
			return new RobotomyRequestForm(target);
		case 3:
			std::cout << "Intern creates form " << name << std::endl;
			return new PresidentialPardonForm(target);
		default:
			throw NoFormException("Intern can't create form (provided form type doesn't exist)");
	}
}