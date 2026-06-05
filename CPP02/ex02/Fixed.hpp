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
	bool	operator>( const Fixed& rhs ) const;
	bool	operator<( const Fixed& rhs ) const;
	bool	operator>=( const Fixed& rhs ) const;
	bool	operator<=( const Fixed& rhs ) const;
	bool	operator==( const Fixed& rhs ) const;
	bool	operator!=( const Fixed& rhs ) const;
	Fixed	operator+( const Fixed& rhs ) const;
	Fixed	operator-( const Fixed& rhs ) const;
	Fixed	operator*( const Fixed& rhs ) const;
	Fixed	operator/( const Fixed& rhs ) const;
	Fixed	operator++( int );
	Fixed&	operator++( void );
	Fixed	operator--( int );
	Fixed&	operator--( void );
	~Fixed( void );

	int					getRawBits( void ) const;
	void				setRawBits( const int raw );
	float				toFloat( void ) const;
	int					toInt( void ) const;
	static Fixed&		min( Fixed& a, Fixed& b );
	static const Fixed&	min( const Fixed& a, const Fixed& b );
	static Fixed&		max( Fixed& a, Fixed& b );
	static const Fixed&	max( const Fixed& a, const Fixed& b );
};

std::ostream&	operator<<( std::ostream & o, const Fixed& i );

#endif
