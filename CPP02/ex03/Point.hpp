#pragma once
#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed	x;
	const Fixed	y;
public:
	Point( void );
	Point( const float x, const float y );
	Point( const Point& src );
	Point&	operator=( const Point& rhs );
	~Point( void );

	Fixed		getX( void ) const;
	Fixed		getY( void ) const;
	std::string	print_format( void ) const;
};

std::ostream&	operator<<( std::ostream & o, const Point& i );

#endif
