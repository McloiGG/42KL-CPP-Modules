#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : materias()
{
}

MateriaSource::MateriaSource(MateriaSource const & other) : materias()
{
	try
	{
		this->copyMaterias(other);
	}
	catch (...)
	{
		this->clearMaterias();
		throw;
	}
}

MateriaSource&	MateriaSource::operator=(MateriaSource const & other)
{
	if (this != &other)
	{
		this->clearMaterias();
		this->copyMaterias(other);
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	this->clearMaterias();
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (m == 0)
		return;
	for (int index = 0; index < 4; ++index)
	{
		if (this->materias[index] == m)
			return;
	}
	for (int index = 0; index < 4; ++index)
	{
		if (this->materias[index] == 0)
		{
			this->materias[index] = m;
			return;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int index = 0; index < 4; ++index)
	{
		if (this->materias[index] != 0
			&& this->materias[index]->getType() == type)
			return this->materias[index]->clone();
	}
	return 0;
}

void	MateriaSource::clearMaterias()
{
	for (int index = 0; index < 4; ++index)
	{
		delete this->materias[index];
		this->materias[index] = 0;
	}
}

void	MateriaSource::copyMaterias(MateriaSource const & other)
{
	for (int index = 0; index < 4; ++index)
	{
		if (other.materias[index] != 0)
			this->materias[index] = other.materias[index]->clone();
	}
}
