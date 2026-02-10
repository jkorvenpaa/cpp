#include "Fixed.hpp"


Fixed::Fixed(): _raw(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}
Fixed::Fixed(const Fixed &copy){

    setRawBits(copy._raw);
    std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &copy){

    std::cout << "Copy assignment operator called\n";
    setRawBits(copy._raw);
    return *this;
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called\n";
    return _raw; 
}

void Fixed::setRawBits( int const raw ){
    _raw = raw;
}