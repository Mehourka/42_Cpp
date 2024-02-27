#pragma once
#include "Fixed.hpp"
#include <iostream>

class Point
{
public:
	Point(); 							// Canonical
	Point(const Point &); 				// Canonical
	virtual ~Point(); 					// Canonical
	Point & operator = (const Point &);	// Canonical

private:
	Fixed _x;
	Fixed _y;

public:
	Point(const float x, const float y);

	Fixed getX() const;
	Fixed getY() const;
	void setX(const Fixed);
	void setY(const Fixed);

	Point operator + (const Point & other) const;
	Point operator - (const Point & other) const;
	Point operator * (const Fixed ) const;
	Fixed operator * (const Point & other) const; // Dot product

};

std::ostream & operator << (std::ostream &, Point);