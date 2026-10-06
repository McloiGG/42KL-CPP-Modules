#include "Array.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <string>

static bool	testIntegers()
{
	const unsigned int	count = 750;
	Array<int>			numbers(count);
	int					mirror[count];
	bool				passed = numbers.size() == count;

	for (unsigned int i = 0; i < count; ++i)
	{
		passed = numbers[i] == 0 && passed;
		mirror[i] = std::rand();
		numbers[i] = mirror[i];
	}
	Array<int>	copy(numbers);
	Array<int>	assigned(2);

	assigned = numbers;
	passed = copy.size() == count && assigned.size() == count && passed;
	for (unsigned int i = 0; i < count; ++i)
		passed = copy[i] == mirror[i] && assigned[i] == mirror[i] && passed;
	copy[0] = -1;
	assigned[count - 1] = -2;
	passed = numbers[0] == mirror[0] && numbers[count - 1] == mirror[count - 1] && passed;
	numbers[1] = -3;
	passed = copy[1] == mirror[1] && assigned[1] == mirror[1] && passed;
	Array<int>&	alias = numbers;

	numbers = alias;
	passed = numbers.size() == count && numbers[1] == -3 && passed;
	std::cout << "Integers, deep copies and self-assignment: " << passed << std::endl;
	return passed;
}

static bool	testStrings()
{
	Array<std::string>	words(2);
	bool				passed = words[0].empty() && words[1].empty();

	words[0] = "hello";
	words[1] = "templates";
	Array<std::string>	copy(words);
	Array<std::string>	assigned;

	assigned = words;
	copy[0] = "copy";
	assigned[1] = "assigned";
	passed = words[0] == "hello" && words[1] == "templates" && passed;
	words[0] = "original";
	passed = copy[0] == "copy" && assigned[0] == "hello" && passed;
	const Array<std::string>	constants(words);

	passed = constants.size() == 2 && constants[0] == "original" && passed;
	std::cout << "Strings and const access: " << passed << std::endl;
	return passed;
}

static bool	testEmptyArrays()
{
	Array<int>	empty;
	Array<int>	zero(0);
	Array<int>	copy(empty);
	Array<int>	assigned(3);
	bool		passed = empty.size() == 0 && zero.size() == 0 && copy.size() == 0;

	assigned = empty;
	passed = assigned.size() == 0 && passed;
	Array<int>	source(1);

	source[0] = 42;
	empty = source;
	passed = empty.size() == 1 && empty[0] == 42 && passed;
	std::cout << "Empty arrays and resizing through assignment: " << passed << std::endl;
	return passed;
}

static bool	testBounds()
{
	Array<int>			numbers(3);
	const Array<int>	constants(numbers);
	Array<int>			empty;
	const std::size_t	indices[] = {3, static_cast<std::size_t>(-2),
		std::numeric_limits<std::size_t>::max()};
	bool				passed = true;

	for (unsigned int i = 0; i < sizeof(indices) / sizeof(indices[0]); ++i)
	{
		try
		{
			numbers[indices[i]] = 0;
			passed = false;
		}
		catch (const std::exception& e)
		{
			std::cout << "Mutable access: " << e.what() << std::endl;
		}
		try
		{
			(void)constants[indices[i]];
			passed = false;
		}
		catch (const std::exception& e)
		{
			std::cout << "Const access: " << e.what() << std::endl;
		}
	}
	try
	{
		(void)empty[0];
		passed = false;
	}
	catch (const std::exception& e)
	{
		std::cout << "Empty access: " << e.what() << std::endl;
	}
	std::cout << "Bounds checks: " << passed << std::endl;
	return passed;
}

int	main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	std::cout << std::boolalpha;
	bool	passed = testIntegers();

	passed = testStrings() && passed;
	passed = testEmptyArrays() && passed;
	passed = testBounds() && passed;
	std::cout << "All tests passed: " << passed << std::endl;
	return passed ? 0 : 1;
}
