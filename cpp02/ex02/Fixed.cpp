#include "Fixed.hpp"

#define Log(x) std::cout << x << std::endl

Fixed::Fixed()
{
	_raw_bits = 0;
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
}

Fixed::~Fixed() { }

Fixed::Fixed(int const integer)
{
	_raw_bits = (integer << _frac_width);
}

Fixed::Fixed(float const fp)
{
	_raw_bits = roundf(fp * (1 << _frac_width));
}

float Fixed::toFloat(void) const
{
	return (float)_raw_bits / (1 << _frac_width);
}

int Fixed::toInt(void) const
{
	return (_raw_bits >> _frac_width);
}

int Fixed::getRawBits() const
{
	return _raw_bits;
}

void Fixed::setRawBits(int const val)
{
	_raw_bits = val;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	this->_raw_bits = rhs.getRawBits();
	return *this;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

Fixed Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return Fixed(a);
	return Fixed(b);
}
