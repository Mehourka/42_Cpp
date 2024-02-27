#include <iostream>

class Fixed
{
private:
	int _n;
	static const int _w = 8;

public:
	Fixed();
	Fixed(int);
	~Fixed();

	int add(Fixed &that) const;
	int add(int that) const;
	int getValue() const;

	Fixed &operator=(Fixed const &rhs);
	Fixed operator+(Fixed const &rhs) const;

};

std::ostream & operator<<(std::ostream &o, Fixed const &rhs);