#pragma once

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contact[8];
	int		_index;
public:
	PhoneBook();
	~PhoneBook();
	int	get_index();
	void  add_contact();
	void  search_contact();
};


