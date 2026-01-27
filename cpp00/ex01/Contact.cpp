#include "Contact.hpp"

Contact::Contact(): _firstname(""), _lastname(""),
_nickname(""), _phone(""), _secret(""){
}

Contact::~Contact(){
}

std::string Contact::get_firstname(){ 
    return _firstname;
}

std::string	Contact::get_lastname(){
    return _lastname;
}

std::string Contact::get_nickname(){
    return _nickname;
}

std::string	Contact::get_phone(){
    return _phone;
}

std::string	Contact::get_secret(){
    return _secret;
}

void	Contact::set_firstname(std::string firstname){
    _firstname = firstname;
}

void	Contact::set_lastname(std::string lastname){
    _lastname = lastname;
}
void    Contact::set_nickname(std::string nickname){
    _nickname = nickname;
}
void	Contact::set_phone(std::string phone){
    _phone = phone;
}
void    Contact::set_secret(std::string secret){
    _secret = secret;

}
