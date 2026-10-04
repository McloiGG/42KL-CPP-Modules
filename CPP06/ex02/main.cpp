#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

static void	testIdentify(Base& object)
{
	std::cout << "Pointer: ";
	identify(&object);
	std::cout << "Reference: ";
	identify(object);
}

int	main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	A		a;
	B		b;
	C		c;
	Base	base;

	testIdentify(a);
	testIdentify(b);
	testIdentify(c);
	testIdentify(base);

	for (int i = 0; i < 5; ++i)
	{
		std::cout << "\n";
		Base*	object = generate();
		testIdentify(*object);
		delete object;
	}
	return 0;
}
