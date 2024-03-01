#pragma once
#include <iostream>

class Fixed
{
private:
	int _raw_bits;
	static const int _w = 8;

public:
	Fixed();							// Canonical
	Fixed(Fixed const &src);			// Canonical
	virtual ~Fixed();					// Canonical
	Fixed &operator=(Fixed const &rhs);	// Canonical

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);
