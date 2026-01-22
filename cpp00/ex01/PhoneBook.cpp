#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
    _index = -1;
}
PhoneBook::~PhoneBook(){

}

int PhoneBook::get_index(){
    if (_index > 7)
        _index = 0;
    else
        _index++;
    return _index;
}

void   PhoneBook::add_contact(){
    std::string input;

    std::cout << "first Name: ";
    std::cin >> input;
    _contact[_index].Contact::set_firstname(input);


    std::cout << "last name: ";
    std::cin >> input;
    _contact[_index].Contact::set_lastname(input); 


    std::cout << "nickname: ";
    std::cin >> input;
    _contact[_index].Contact::set_nickname(input); 


    std::cout << "phone number: ";
    std::cin >> input;
    _contact[_index].Contact::set_phone(input); 

    std::cout << "Darkest secret: ";
    std::getline(std::cin, input);
    _contact[_index].Contact::set_secret(input);
}

void   PhoneBook::search_contact(){

    int pos = 0; // std::cin
    std::cout << pos << "|";
    std::cout << _contact[pos].Contact::get_firstname() << "|" << std::endl;
}