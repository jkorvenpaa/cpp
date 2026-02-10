#pragma once

#include <iostream>
#include <fstream>
#include <cmath>

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

};

std::ostream& operator<<(std::ostream& os, const Fixed& num);

