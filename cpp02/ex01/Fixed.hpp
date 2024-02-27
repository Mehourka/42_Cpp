#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _raw_bits;
	static const int _frac_width = 8;

public:
	Fixed();				 // Canonical
	Fixed(Fixed const &); // Canonical
	Fixed(int const);
	Fixed(float const);
	virtual ~Fixed();		 // Canonical

	Fixed &operator=(Fixed const &rhs); // Canonical

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);
