#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	_index = -1;
}
PhoneBook::~PhoneBook(){

}

int PhoneBook::get_index(){
	if (_index >= 7)
		_index = 0;
	else
		_index++;
	return _index;
}

std::string	display_field(std::string field){
	std::string input;

	while (1){
		std::cout << BLUE << field << RESET;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit (0);
		if (!input.empty())
			break;
	}
	return (input);
}

void   PhoneBook::add_contact(){
	std::string input;

	input = display_field("first name: ");
	_contact[_index].set_firstname(input);
	input = display_field("last name: ");
	_contact[_index].set_lastname(input); 
	input = display_field("nick name: ");
	_contact[_index].set_nickname(input);
	input = display_field("phone number: ");
	_contact[_index].set_phone(input); 
	input = display_field("darkest secret: ");
	_contact[_index].set_secret(input);
	std::cout << PINK << "Added contact " << _index << " to PhoneBook"
		<< RESET << std::endl;  
}

std::string	check_name(std::string name){
	if (name.length() > 10){
		name = name.substr(0, 9) + '.';
	}
	return (name);
}

int	valid_index(std::string input){

	if (input.length() == 1 && (input[0] >= '0' && input[0] <= '7'))
		return ((int)input[0] - 48);
	else
		return (-1);
}

void   PhoneBook::search_contact(){

	std::string name;
	std::string input;
	int i = 0;

	std::cout << std::setw(10) << "index " << "|"
		<< std::setw(10) << "first name"<< "|"
		<< std::setw(10) << "last name" << "|"
		<< std::setw(10) << "nickname" << std::endl;
	for (int pos = 0; pos <= 7; pos++){
		std::cout << std::setw(10) << pos << "|";
		name = check_name(_contact[pos].get_firstname());
		std::cout << std::setw(10) << name << "|";
		name = check_name(_contact[pos].get_lastname());
		std::cout << std::setw(10) << name << "|";
		name = check_name(_contact[pos].get_nickname());
		std::cout << std::setw(10) << name << std::endl;
	}
	while (1){
		std::cout << BLUE << "Index to display (number between 0 and 7): " << RESET;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit (0);
		i = valid_index(input);
		if (i >= 0)
			break ;
	}
	if (_contact[i].get_firstname().empty()){
		std::cout << PINK << "No saved contact on index " << i << std::endl;
		return ;
	}
	std::cout << PINK << "CONTACT " << i << std::endl
		<< "first name: " <<_contact[i].get_firstname() << std::endl
		<< "last name: " <<_contact[i].get_lastname() << std::endl
		<< "nickname: " << _contact[i].get_nickname() << std::endl
		<< "phone number: " << _contact[i].get_phone() << std::endl
		<< "darkest secret: " << _contact[i].get_secret() << std::endl << RESET;
}
