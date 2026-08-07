#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type)
{
}

AMateria::AMateria() : type("")
{
}

AMateria::AMateria(AMateria const & other) : type(other.type)
{
}

AMateria&	AMateria::operator=(AMateria const & other)
{
	(void)other;
	return *this;
}

AMateria::~AMateria()
{
}

std::string const &	AMateria::getType() const
{
	return this->type;
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}
