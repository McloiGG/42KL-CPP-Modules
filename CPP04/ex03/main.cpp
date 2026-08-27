#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource*	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter*	me = new Character("me");

	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter*	bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	// {
	// 	ICharacter*	tmpChar = new Character("tmp");
	// 	AMateria*	tmpMat = src->createMateria("ice");

	// 	tmpChar->equip(tmpMat);
	// 	tmpChar->use(0, *bob);

	// 	AMateria*	saved = tmpMat;

	// 	tmpChar->unequip(0);
	// 	tmpChar->use(0, *bob);

	// 	delete saved;
	// 	delete tmpChar;
	// }

	delete bob;
	delete me;
	delete src;

	return 0;
}
