#pragma once

#include <iostream>

class Fixed
{
private:
	int _raw;
	static const int _bits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &copy);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

