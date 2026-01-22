#pragma once

#include <iostream>

class Contact
{
private:
	std::string	_firstname;
	std::string _lastname;
	std::string _nickname;
	std::string _phone;
	std::string _secret;
public:
	Contact();
	~Contact();

	std::string	get_firstname();
	std::string	get_lastname();
	std::string	get_nickname();
	std::string	get_phone();
	std::string	get_secret();

	void	set_firstname(std::string firstname);
	void	set_lastname(std::string lastname);
	void	set_nickname(std::string nickname);
	void	set_phone(std::string phone);
	void	set_secret(std::string secret);
};
