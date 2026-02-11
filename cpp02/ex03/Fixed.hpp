#pragma once

#include <iostream>
#include <fstream>
#include <math.h>

class Fixed
{
private:
	int _raw;
	static const int _bits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed& copy);
	

	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFloat(void) const;

	bool operator>(const Fixed& num)const;
	bool operator<(const Fixed& num)const;
	bool operator>=(const Fixed& num)const;
	bool operator<=(const Fixed& num)const;
	bool operator==(const Fixed& num)const;
	bool operator!=(const Fixed& num)const;
	Fixed operator+(const Fixed& num);
	Fixed operator-(const Fixed& num);
	Fixed operator*(const Fixed& num);
	Fixed operator/(const Fixed& num);
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& os, const Fixed& num);

