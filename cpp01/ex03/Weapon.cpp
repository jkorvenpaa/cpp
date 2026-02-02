#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
}

Weapon::~Weapon()
{
}

std::string	Weapon::get_Type(){
    return (_type);
}

void	Weapon::set_Type(std::string type){
    _type = type; 
}