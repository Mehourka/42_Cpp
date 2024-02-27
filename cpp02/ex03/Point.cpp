#include "Point.hpp"

Point::Point()
{
	_x = Fixed(0);
	_y = Fixed(0);
}

Point::Point(const Point &other)
{
	_x = other.getX();
	_y = other.getY();
}

Point::~Point() {}

Point & Point::operator = (const Point &other)
{
	_x = other.getX();
	_y = other.getY();
	return *this;
}

Point::Point(const float x, const float y)
{
	_x = Fixed(x);
	_y = Fixed(y);
}

Fixed Point::getX() const { return Fixed(_x); }
Fixed Point::getY() const { return Fixed(_y); }

std::ostream & operator << (std::ostream &out, Point pt)
{
	out << "Point("
		<< pt.getX() << ", " << pt.getY() << ")"
		<< std::endl;
	return out;
}