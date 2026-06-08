#include "Point.hpp"
#include <sstream>

Point::Point( void ) : x( 0 ), y( 0 )
{
}

Point::Point( const float x, const float y ) : x( x ), y( y )
{
	std::cout << this->print_format() << std::endl;
}

Point::Point( const Point& src ) : x( src.getX() ), y( src.getY() )
{
}

Point&	Point::operator=( const Point& rhs )
{
	(void)rhs;
	return *this;
}

std::ostream&	operator<<( std::ostream & o, const Point& i )
{
	o << i.print_format();
	return o;
}

Point::~Point( void )
{
}

Fixed	Point::getX( void ) const
{
	return this->x;
}

Fixed	Point::getY( void ) const
{
	return this->y;
}

Fixed	Point::cross_product(Point const a, Point const b, Point const c)
{
	const Fixed	ax = (a.getX() - c.getX());
	const Fixed	ay = (a.getY() - c.getY());
	const Fixed	bx = (b.getX() - c.getX());
	const Fixed	by = (b.getY() - c.getY());

	return (ax * by) - (ay * bx);
}

std::string	Point::print_format( void ) const
{
	std::stringstream ss;

	ss << "(" << this->getX().toFloat() << ", " << this->getY().toFloat() << ")";
	return ss.str();
}
