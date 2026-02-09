#include "Fixed.hpp"


Fixed::Fixed(): _fixpoint(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}
Fixed::Fixed(const Fixed &copy){

    setRawBits(copy._fixpoint);
    std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &copy){

    std::cout << "Copy assignment operator called\n";
    setRawBits(copy._fixpoint);
    return *this;
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called\n";
    return _fixpoint; 
}

void Fixed::setRawBits( int const raw ){
    _fixpoint = raw;
}