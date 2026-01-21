#pragma once

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contact;
	int		_last_index;
	int		_total;
public:
	PhoneBook(Contact _contact, int _last_index, int _total);
	~PhoneBook();
};

PhoneBook::PhoneBook(Contact _contact, int _last_index, int _total)
{
}

PhoneBook::~PhoneBook()
{
}
