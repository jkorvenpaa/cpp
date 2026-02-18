#pragma once

#include  <iostream>

class Animal
{
protected:
	std::string _type;
public:
	Animal();
	virtual ~Animal();
	Animal(const Animal &copy);
    Animal &operator=(const Animal &copy);
	virtual void	makeSound() const = 0;
	std::string	getType()const;
};