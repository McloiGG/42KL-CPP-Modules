#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const	Animal* meta = new Animal();
	const	Animal* j = new Dog();
	const	Animal* i = new Cat();

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;

	std::cout << "\n=== Wrong polymorphism ===" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	wrongCat->makeSound();
	wrongMeta->makeSound();

	delete wrongCat;
	delete wrongMeta;

	return 0;
}
