#pragma once

#include <iostream>
#include <iomanip>
#include "Contact.hpp"


#define RESET   "\033[0m"
#define BLUE    "\x1b[38;2;135;206;235m"
#define GOLD 	"\033[1;33m"
#define PINK	"\033[95m"

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


