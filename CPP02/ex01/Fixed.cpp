#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ) : raw_bits( 0 )
{
	std::cout << "Default constructor called" << std::endl;
}

// Fixed::Fixed( const Fixed& src ) : raw_bits( src.raw_bits )
// {
// 	std::cout << "Copy constructor called" << std::endl;
// }

// Fixed::Fixed( const Fixed& src )
// {
// 	std::cout << "Copy constructor called" << std::endl;
// 	this->raw_bits = src.getRawBits();
// }

Fixed::Fixed( const Fixed& src ) : raw_bits( src.getRawBits() )
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed( const int n )
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(n << this->fractional_bits);
}

Fixed::Fixed( const float f )
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf( f * ( 1 << this->fractional_bits ) ));
}

Fixed&	Fixed::operator=( const Fixed& rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &rhs )
		this->setRawBits( rhs.getRawBits() );
	return *this;
}

std::ostream&	operator<<( std::ostream & o, const Fixed& i )
{
	o << i.toFloat();
	return o;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->raw_bits;
}

void	Fixed::setRawBits( const int raw )
{
	this->raw_bits = raw;
}

float	Fixed::toFloat( void ) const
{
	return static_cast<float>( this->getRawBits() ) / ( 1 << this->fractional_bits );
}

int	Fixed::toInt( void ) const
{
	return this->getRawBits() / ( 1 << this->fractional_bits );
}
