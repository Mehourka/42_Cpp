#include "Fixed.hpp"

// --------------- Bool oberloads -------------------- //
bool Fixed::operator>(Fixed const &rhs) const
{
   return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(Fixed const &rhs) const
{
   return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const &rhs) const
{

   return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const &rhs) const
{

   return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const &rhs) const
{

   return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const &rhs) const
{

   return this->getRawBits() != rhs.getRawBits();
}

// --------------- Arithmetic overloads -------------------- //
Fixed Fixed::operator+(Fixed const &rhs) const
{
   Fixed fix;
   int result = this->getRawBits() + rhs.getRawBits();
   fix.setRawBits(result);
   return fix;
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
   Fixed fix;
   int result = this->getRawBits() - rhs.getRawBits();
   fix.setRawBits(result);
   return fix;
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
   Fixed fix;
   int64_t result = ((int64_t)this->getRawBits() * (int64_t)rhs.getRawBits());
   result = result >> _frac_width;
   fix.setRawBits((int) result);
   return fix;
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
   Fixed fix;
   int64_t result = static_cast<int64_t>(this->getRawBits()) << _frac_width;
   result = result / rhs.getRawBits();
   fix.setRawBits(static_cast<int>(result));
   return fix;
}


// --------------- Increment Overload  -------------------- //
Fixed & Fixed::operator ++ () {
   ++_raw_bits;
   return *this;
}

Fixed Fixed::operator ++ (int) {
   Fixed tmp;
   tmp.setRawBits(_raw_bits++);
   return tmp;
}

Fixed & Fixed::operator -- () {
   --_raw_bits;
   return *this;
}

Fixed Fixed::operator -- (int) {
   Fixed tmp;
   tmp.setRawBits(_raw_bits--);
   return tmp;
}


// --------------- ostream Overload  -------------------- //
std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
   o << rhs.toFloat();
   return o;
}
