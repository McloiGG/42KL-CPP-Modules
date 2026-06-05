#include "Point.hpp"

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

std::string	Point::print_format( void ) const
{
	return "(" + std::to_string( this->getX().toFloat() ) + ", " + std::to_string( this->getY().toFloat() ) + ")";
}