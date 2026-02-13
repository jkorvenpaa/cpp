#include "ClapTrap.hpp"

ClapTrap::ClapTrap():_name(""),_hitPoints(0), _energyPoints(0), _damage(0){
}

ClapTrap::~ClapTrap(){
}

ClapTrap::ClapTrap(std::string name): _hitPoints(10), _energyPoints(10), _damage(10){

}

ClapTrap::ClapTrap(const ClapTrap &copy){
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy){
}

void ClapTrap::attack(const std::string& target){
    
}
void ClapTrap::takeDamage(unsigned int amount){

}
void ClapTrap::beRepaired(unsigned int amount){

}