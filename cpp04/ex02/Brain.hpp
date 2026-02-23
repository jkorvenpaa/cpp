#pragma once

#include <iostream>

class Brain
{
private:
    std::string _ideas[100];
public:
    Brain();
    ~Brain();
    Brain (const Brain &copy);
	Brain &operator=(const Brain &copy);
    std::string	get_ideas(unsigned int index);
    void    set_ideas(std::string ideas, unsigned int index);
};


