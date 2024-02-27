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

Point &Point::operator=(const Point &other)
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
void Point::setX(const Fixed val) { _x = val; }
void Point::setY(const Fixed val) { _y = val; }

Point Point::operator+(const Point &other) const
{
	Point pt;
	pt.setX(this->getX() + other.getX());
	pt.setY(this->getY() + other.getY());
	return pt;
}

Point Point::operator-(const Point &other) const
{
	Point pt;
	pt.setX(this->getX() - other.getX());
	pt.setY(this->getY() - other.getY());
	return pt;
}

Point Point::operator*(const Fixed C) const
{
	Point pt;
	pt.setX(this->getX() * C);
	pt.setY(this->getY() * C);
	return pt;
}

Fixed Point::operator*(const Point &other) const
{
	return (this->getX() * other.getX() + this->getY() * other.getY());
}

std::ostream &operator<<(std::ostream &out, Point pt)
{
	out << "Point("
		<< pt.getX() << ", " << pt.getY() << ") "
		<< std::ends;
	return out;
}
