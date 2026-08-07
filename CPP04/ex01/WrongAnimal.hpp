#pragma once
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class	WrongAnimal
{
private:
	std::string	type;
protected:
	explicit WrongAnimal(const std::string& animalType);
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal&	operator=(const WrongAnimal& other);
	virtual ~WrongAnimal();

	const std::string&	getType() const;
	void			makeSound() const;
};

#endif
