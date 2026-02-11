#include "Fixed.hpp"


Fixed::Fixed(): _raw(0){
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& copy){
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

void Fixed::setRawBits(int const raw){
	_raw = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& num){
	os << num.toFloat();
	return os;
}

Fixed::Fixed(const int value){
	std::cout << "Int constructor called\n";
	_raw = value << _bits;
}
Fixed::Fixed(const float value){
	std::cout << "Float constructor called\n";
	_raw = roundf(value *(1 << _bits));
}
int Fixed::toInt(void)const{
	return _raw >> _bits;
}
float Fixed::toFloat(void)const{
	return float(_raw) / float(1 << _bits);
}


//Comparison Operators
bool Fixed::operator>(const Fixed& num)const{
	return this->_raw > num._raw;
}
bool Fixed::operator<(const Fixed& num)const{
	return this->_raw < num._raw;
}
bool Fixed::operator>=(const Fixed& num)const{
	return this->_raw >= num._raw;
}
bool Fixed::operator<=(const Fixed& num)const{
	return this->_raw <= num._raw;
}
bool Fixed::operator==(const Fixed& num)const{
	return this->_raw == num._raw;
}
bool Fixed::operator!=(const Fixed& num)const{
	return this->_raw != num._raw;
}
//Arithmetic Operators:
Fixed Fixed::operator+(const Fixed& num){
	Fixed res;
	res.setRawBits(this->_raw + num._raw);
	return res;
}
Fixed Fixed::operator-(const Fixed& num){
	Fixed res;
	res.setRawBits(this->_raw - num._raw);
	return res;
}
Fixed Fixed::operator*(const Fixed& num){
	Fixed res;
	res.setRawBits(this->_raw * num._raw >> _bits);
	return res;
}
Fixed Fixed::operator/(const Fixed& num){
	Fixed res;
	res.setRawBits(this->_raw / num._raw << _bits);
	return res;
}

//POST-increment (a++) returns a value before incrementing
Fixed Fixed::operator++(int){
	Fixed temp = (*this);
	this->_raw += 1;
	return temp;
}
Fixed Fixed::operator--(int){
	Fixed temp = (*this);
	this->_raw -= 1;
	return temp;
}

//PRE-increment (++a) returns reference to incremented value
Fixed& Fixed::operator++(){
	this->_raw += 1;
	return *this;
}

Fixed& Fixed::operator--(){
	this->_raw += 1;
	return *this;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
	return (a < b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
	return (a > b) ? a : b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
	return (a > b) ? a : b;
}