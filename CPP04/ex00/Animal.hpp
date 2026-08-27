#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class	Animal
{
protected:
	std::string	type;
	explicit Animal(const std::string& animalType);
public:
	Animal();
	Animal(const Animal& other);
	Animal&	operator=(const Animal& other);
	virtual ~Animal();

	const std::string&	getType() const;
	virtual void		makeSound() const;
};

#endif
