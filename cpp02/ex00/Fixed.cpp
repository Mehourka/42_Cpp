#include "Fixed.hpp"

Fixed::Fixed() {}
Fixed::Fixed(int value): _n(value){}

Fixed::~Fixed() {}

int Fixed::add(Fixed &that) const{

	return (this->getValue() + that.getValue());
}

int Fixed::add(int num) const{

	return this->getValue() + num;
}

int Fixed::getValue() const {

	return _n;
}
Fixed& Fixed::operator=(Fixed const & rhs) {

	this->_n = rhs.getValue();
	return *this;
}

Fixed Fixed::operator+(Fixed const & rhs) const {

	return Fixed(this->add(rhs.getValue()));
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs) {

	o << rhs.getValue();
	return o;
}
