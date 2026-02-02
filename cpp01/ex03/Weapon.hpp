#pragma once
#include <iostream>

class Weapon
{
private:
	std::string _type;
public:
	Weapon(std::string type);
	~Weapon();
	std::string	get_Type();
	void	set_Type(std::string);
};


