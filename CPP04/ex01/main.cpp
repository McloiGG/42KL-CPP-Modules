#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	{
		const int		count = 6;
		const Animal*	animals[count];

		std::cout << "\n=== Animal array ===" << std::endl;
		for (int index = 0; index < count / 2; ++index)
			animals[index] = new Dog();
		for (int index = count / 2; index < count; ++index)
			animals[index] = new Cat();
		for (int index = 0; index < count; ++index)
			delete animals[index];
	}
	{
		std::cout << "\n=== Deep copy test ===" << std::endl;
		const Dog*	j = new Dog();
		const Cat*	i = new Cat();
		Dog			jCopy(*j);
		Dog			jAssigned;
		Cat			iCopy(*i);
		Cat			iAssigned;

		jAssigned = *j;
		iAssigned = *i;

		delete j;
		delete i;

		jCopy.makeSound();
		jAssigned.makeSound();
		iCopy.makeSound();
		iAssigned.makeSound();
	}
		return 0;
}
