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

void   PhoneBook::add_contact(){
	std::string input;

	while (input.empty()){
		std::cout << "first name: ";
		std::getline(std::cin, input);
	}
	_contact[_index].Contact::set_firstname(input);
	while (1){
		std::cout << "last name: ";
		std::getline(std::cin, input);
		if (!input.empty())
			break;
	}
	_contact[_index].Contact::set_lastname(input); 

	while (1){
		std::cout << "nickname: ";
		std::getline(std::cin, input);
		if (!input.empty())
			break;
	}
	_contact[_index].Contact::set_nickname(input);

	while (1){
		std::cout << "phone number: ";
		std::getline(std::cin, input);
		if (!input.empty())
			break;
	}
	_contact[_index].Contact::set_phone(input); 

	while (1){
		std::cout << "Darkest secret: ";
		std::getline(std::cin, input);
		if (!input.empty())
			break;
	}
	_contact[_index].Contact::set_secret(input);
	std::cout << "Added contact " << _index << " to PhoneBook" << std::endl;  
}

void   PhoneBook::search_contact(){

	int pos = 0; // std::cin
	std::cout << pos << "|";
	std::cout << _contact[pos].Contact::get_firstname() << "|" << std::endl;
	std::cout << _contact[pos].get_secret() << std::endl;
}
/*
setw(10);
std::cin fhesukhfkueshaku    \n
input fhesukhfkueshaku
std::cin     \n
ignore
std::cin hdhakff fehsfuksehaklu hfueskhakfuhsel\n
 // std::cin.ignore();



*/