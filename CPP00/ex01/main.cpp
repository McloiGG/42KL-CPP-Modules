#include "PhoneBook.hpp"
#include "trim.h"
#include <iostream>

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "\nEOF detected. Exiting..." << std::endl;
			break ;
		}
		trim(command);
		if (command == "ADD")
		{
			if (!phoneBook.addContact())
				break ;
		}
		else if (command == "SEARCH")
		{
			if (!phoneBook.searchContacts())
				break ;
		}
		else if (command == "EXIT")
		{
			std::cout << "Exiting..." << std::endl;
			break ;
		}
	}
	return (0);
}
