#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _raw_bits;
	static const int _frac_width = 8;

public:
	Fixed();				 			// Canonical
	Fixed(Fixed const &);				// Canonical
	virtual ~Fixed();		 			// Canonical
	Fixed &operator=(Fixed const &rhs); // Canonical

	Fixed(int const);
	Fixed(float const);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat( void ) const;
	int		toInt( void ) const;

public:
	// Operator Overloads
    bool operator  > (Fixed const & rhs) const;
    bool operator  < (Fixed const & rhs) const;
    bool operator >= (Fixed const & rhs) const;
    bool operator <= (Fixed const & rhs) const;
    bool operator == (Fixed const & rhs) const;
    bool operator != (Fixed const & rhs) const;

	Fixed operator + (Fixed const & rhs) const;
	Fixed operator - (Fixed const & rhs) const;
	Fixed operator * (Fixed const & rhs) const;
	Fixed operator / (Fixed const & rhs) const;

	Fixed & operator ++ ();
	Fixed 	operator ++ (int);
	Fixed & operator -- ();
	Fixed	operator -- (int);

public:
	// Static member functions
	static Fixed & max(Fixed &, Fixed &);
	static Fixed max(const Fixed &, const Fixed &);
	static Fixed & min(Fixed &, Fixed &);
	static Fixed min(const Fixed &, const Fixed &);

};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);