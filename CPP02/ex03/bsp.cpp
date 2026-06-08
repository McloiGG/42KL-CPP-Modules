#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	ab = Point::cross_product(a, b, point);
	Fixed	bc = Point::cross_product(b, c, point);
	Fixed	ca = Point::cross_product(c, a, point);

	return (ab > 0 && bc > 0 && ca > 0) || (ab < 0 && bc < 0 && ca < 0);
}
