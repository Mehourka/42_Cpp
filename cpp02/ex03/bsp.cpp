#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	// Determin if a point is inside a triangle
	// Using triangle barycentrique coordinates
	Fixed one(1);
	Fixed zero(0);

	Point v0, v1, v2;
	v0 = c - a;
	v1 = b - a;
	v2 = point - a;

	Fixed inv_denom = (v0 * v0) * (v1* v1) - (v0 * v1) * (v0 * v1);
	if (inv_denom == zero)
	{
		return false;
	}
	inv_denom = Fixed(1) / inv_denom;
	Fixed u = ((v1* v1) * (v0 * v2) - (v0 * v1) *(v1 * v2)) * inv_denom;
	Fixed v = ((v0 * v0) * (v1* v2) - (v0 * v1) * (v0 * v2)) * inv_denom;
	
	return ((u > zero) && (v > zero) && (u + v < one));
}
