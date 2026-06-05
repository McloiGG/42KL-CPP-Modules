#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int					raw_bits;
	static const int	fractional_bits = 8;

public:
	Fixed( void );
	Fixed( const Fixed& src );
	Fixed&	operator=( const Fixed& rhs );
	~Fixed( void );

	int		getRawBits( void ) const;
	void	setRawBits( const int raw );
};

#endif
