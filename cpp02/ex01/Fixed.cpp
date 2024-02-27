#include "Fixed.hpp"

#define Log(x) std::cout << x << std::endl

Fixed::Fixed() {

	_raw_bits = 0;
	Log("Default constructor called");
}

Fixed::Fixed(Fixed const & src) {
	Log("Copy constructor called");
	*this = src;
}

Fixed::~Fixed() {
	Log("Destructor called");
}

Fixed::Fixed(int const integer) {
	_raw_bits = (integer << _frac_width);
	Log("Int constructor called");
}

Fixed::Fixed(float const fp) {
	_raw_bits =  round(fp * (1 << _frac_width));
	Log("Int constructor called");
}

float Fixed::toFloat( void ) const
{
	return (float) _raw_bits / (1 << _frac_width);
}

int Fixed::toInt( void ) const
{
	return (_raw_bits >> _frac_width);
}

int	Fixed::getRawBits() const {
	Log("getRawBits member function called");
	return _raw_bits;
}

void	Fixed::setRawBits( int const val ) {
	Log("setRawBits member function called");
	_raw_bits = val;
}



Fixed& Fixed::operator=(Fixed const & rhs) {
	Log("Copy assignment operator called");
	this->_raw_bits = rhs.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream & o, Fixed const & rhs){
    o << rhs.toFloat();
    return o;
}

