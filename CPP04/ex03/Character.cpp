#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : name(""), inventory()
{
}

Character::Character(std::string const & name) : name(name), inventory()
{
}

Character::Character(Character const & other) : name(other.name), inventory()
{
	try
	{
		this->copyInventory(other);
	}
	catch (...)
	{
		this->clearInventory();
		throw;
	}
}

Character&	Character::operator=(Character const & other)
{
	if (this != &other)
	{
		this->clearInventory();
		this->name = other.name;
		this->copyInventory(other);
	}
	return *this;
}

Character::~Character()
{
	this->clearInventory();
}

std::string const &	Character::getName() const
{
	return this->name;
}

void	Character::equip(AMateria* m)
{
	if (m == 0)
		return;
	for (int index = 0; index < 4; ++index)
	{
		if (this->inventory[index] == m)
			return;
	}
	for (int index = 0; index < 4; ++index)
	{
		if (this->inventory[index] == 0)
		{
			this->inventory[index] = m;
			return;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return;
	this->inventory[idx] = 0;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || this->inventory[idx] == 0)
		return;
	this->inventory[idx]->use(target);
}

void	Character::clearInventory()
{
	for (int index = 0; index < 4; ++index)
	{
		delete this->inventory[index];
		this->inventory[index] = 0;
	}
}

void	Character::copyInventory(Character const & other)
{
	for (int index = 0; index < 4; ++index)
	{
		if (other.inventory[index] != 0)
			this->inventory[index] = other.inventory[index]->clone();
	}
}
