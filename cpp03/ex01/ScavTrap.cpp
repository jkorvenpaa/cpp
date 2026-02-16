#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){

}

ScavTrap::~ScavTrap(){

}

ScavTrap::ScavTrap(std::string name){

}

ScavTrap::ScavTrap(const ScavTrap &copy){

}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy){

}

void ScavTrap::guardGate(){
 std::cout << VIOLET << _name << " ScavTrap is now in Gate keeper mode\n" << RESET;
}

void ScavTrap::attack(const std::string& target){

}
