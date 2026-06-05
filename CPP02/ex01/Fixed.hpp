#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
class Fixed
{
private:
	int					raw_bits;
	static const int	fractional_bits = 8;

public:
	Fixed( void );
	Fixed( const int n );
	Fixed( const float f );
	Fixed( const Fixed& src );
	Fixed&	operator=( const Fixed& rhs );
	~Fixed( void );

	int		getRawBits( void ) const;
	void	setRawBits( const int raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream&	operator<<( std::ostream & o, const Fixed& i );

#endif
