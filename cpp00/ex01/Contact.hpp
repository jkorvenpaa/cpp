#pragma once

#include <iostream>

class Contact
{
private:
	int	index;
	std::string	_firstname;
	std::string _lastname;
	std::string _nickname;
	//phone
	//secret
public:
	Contact(/* args */);
	~Contact();
};

Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}