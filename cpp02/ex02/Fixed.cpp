#include "Fixed.hpp"


Fixed::Fixed(): _raw(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
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
///

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
/*<< = “multiply by 2 for each shift”

>> = “divide by 2 for each shift”*/



bool Fixed::operator>(const Fixed& num){
	return this->_raw > num._raw;
}
bool Fixed::operator<(const Fixed& num){
	return this->_raw < num._raw;
}
bool Fixed::operator>=(const Fixed& num){
	return this->_raw >= num._raw;
}
bool Fixed::operator<=(const Fixed& num){
	return this->_raw <= num._raw;
}
bool Fixed::operator==(const Fixed& num){
	return this->_raw == num._raw;
}
bool Fixed::operator!=(const Fixed& num){
	return this->_raw != num._raw;
}
const Fixed& Fixed::operator+(const Fixed& num){
	return this->_raw + num._raw;
}
const Fixed& Fixed::operator-(const Fixed& num){
	return this->_raw - num._raw;
}
const Fixed& Fixed::operator*(const Fixed& num){
	return this->_raw * num._raw;
}
const Fixed& Fixed::operator/(const Fixed& num){
	return this->_raw / num._raw;
}
Fixed& Fixed::operator++(){
	this->_raw += 1;
	return *this;
}
Fixed Fixed::operator++(int){
	this->_raw += 1;
	return *this;
}
Fixed& Fixed::operator--(){
	Fixed temp(*this);
	this->_raw -= 1;
	return temp;
}
Fixed Fixed::operator--(int){
	Fixed temp(*this);
	this->_raw -= 1;
	return temp;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b){

}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b){

}
Fixed& Fixed::min(Fixed& a, Fixed& b){

}
Fixed& Fixed::max(Fixed& a, Fixed& b){

}