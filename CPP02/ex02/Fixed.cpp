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
}

Fixed::Fixed( const int n )
{
	this->setRawBits(n << this->fractional_bits);
}

Fixed::Fixed( const float f )
{
	this->setRawBits(roundf( f * ( 1 << this->fractional_bits ) ));
}

Fixed&	Fixed::operator=( const Fixed& rhs )
{
	if ( this != &rhs )
		this->setRawBits( rhs.getRawBits() );
	return *this;
}

std::ostream&	operator<<( std::ostream & o, const Fixed& i )
{
	o << i.toFloat();
	return o;
}

bool	Fixed::operator>( const Fixed& rhs ) const
{
	return this->getRawBits() > rhs.getRawBits();
}

bool	Fixed::operator<( const Fixed& rhs ) const
{
	return this->getRawBits() < rhs.getRawBits();
}

bool	Fixed::operator>=( const Fixed& rhs ) const
{
	return this->getRawBits() >= rhs.getRawBits();
}

bool	Fixed::operator<=( const Fixed& rhs ) const
{
	return this->getRawBits() <= rhs.getRawBits();
}

bool	Fixed::operator==( const Fixed& rhs ) const
{
	return this->getRawBits() == rhs.getRawBits();
}

bool	Fixed::operator!=( const Fixed& rhs ) const
{
	return this->getRawBits() != rhs.getRawBits();
}

Fixed	Fixed::operator+( const Fixed& rhs ) const
{
	Fixed	result;

	result.setRawBits( this->getRawBits() + rhs.getRawBits() );
	return result;
}

Fixed	Fixed::operator-( const Fixed& rhs ) const
{
	Fixed	result;

	result.setRawBits( this->getRawBits() - rhs.getRawBits() );
	return result;
}

Fixed	Fixed::operator*( const Fixed& rhs ) const
{
	Fixed	result;

	result.setRawBits( ( static_cast<int64_t>( this->getRawBits() ) * rhs.getRawBits() ) >> this->fractional_bits );
	return result;
}

Fixed	Fixed::operator/( const Fixed& rhs ) const
{
	Fixed	result;

	result.setRawBits( ( static_cast<int64_t>( this->getRawBits() ) << this->fractional_bits ) / rhs.getRawBits() );
	return result;
}

Fixed	Fixed::operator++( int )
{
	Fixed	temp( *this );

	this->setRawBits( this->getRawBits() + 1 );
	return temp;
}

Fixed&	Fixed::operator++( void )
{
	this->setRawBits( this->getRawBits() + 1 );
	return *this;
}

Fixed	Fixed::operator--( int )
{
	Fixed	temp( *this );

	this->setRawBits( this->getRawBits() - 1 );
	return temp;
}

Fixed&	Fixed::operator--( void )
{
	this->setRawBits( this->getRawBits() - 1 );
	return *this;
}

Fixed::~Fixed( void )
{
}

int	Fixed::getRawBits( void ) const
{
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
	return this->getRawBits() >> this->fractional_bits;
}

Fixed&	Fixed::min( Fixed& a, Fixed& b )
{
	return ( ( a < b ) ? a : b );
}

const Fixed&	Fixed::min( const Fixed& a, const Fixed& b )
{
	return ( ( a < b ) ? a : b );
}

Fixed&	Fixed::max( Fixed& a, Fixed& b )
{
	return ( ( a > b ) ? a : b );
}

const Fixed&	Fixed::max( const Fixed& a, const Fixed& b )
{
	return ( ( a > b ) ? a : b );
}
