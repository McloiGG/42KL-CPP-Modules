#include "iter.h"
#include <iostream>
#include <string>

template <typename T>
void	print(const T& value)
{
	std::cout << value << std::endl;
}

void	increment(int& value)
{
	++value;
}

int	main()
{
	int			numbers[] = {0, 1, 2, 3, 4};
	const int	constants[] = {10, 20, 30};
	const std::string	words[] = {"hello", "templates"};

	::iter(numbers, 5, print<int>);
	std::cout << "Mutable array after increment:" << std::endl;
	::iter(numbers, 5, increment);
	::iter(numbers, 5, print<int>);
	std::cout << "Const arrays:" << std::endl;
	::iter(constants, 3, print<int>);
	::iter(words, 2, print<std::string>);
}
