#include "PhoneBook.hpp"
#include "trim.h"

#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>

PhoneBook::PhoneBook(void) :
	_size(0),
	_nextIndex(0)
{
}

std::string	PhoneBook::formatColumn(const std::string& text)
{
	if (text.length() > 10)
		return (text.substr(0, 9) + ".");
	return (text);
}

bool	PhoneBook::readRequiredField(const std::string& label, std::string& value)
{
	while (true)
	{
		std::cout << label;
		if (!std::getline(std::cin, value))
		{
			std::cout << "\nEOF detected. Exiting." << std::endl;
			return (false);
		}
		if (!trim_copy(value).empty())
			return (true);
		std::cout << "Field cannot be empty." << std::endl;
	}
}

bool	PhoneBook::readNameField(const std::string& label, std::string& value)
{
	while (readRequiredField(label, value))
	{
		trim(value);
		trim_inner(value);
		if (isNameValid(value))
			return (true);
		std::cout << "Name can contain only letters, spaces, hyphens, "
			"and apostrophes. Spaces, hyphens, and apostrophes must be "
			"between letters." << std::endl;
	}
	return (false);
}

bool	PhoneBook::readPhoneNumberField(const std::string& label, std::string& value)
{
	while (readRequiredField(label, value))
	{
		trim(value);
		if (isPhoneNumberValid(value))
			return (true);
		std::cout << "Phone number must use E.164 format: +[1-9][0-9]{0,14}" << std::endl;
	}
	return (false);
}

bool	PhoneBook::isAlphabetic(char c)
{
	return (std::isalpha(static_cast<unsigned char>(c)) != 0);
}

bool	PhoneBook::isNameValid(const std::string& value)
{
	std::string::size_type	i;
	char					c;

	if (value.empty())
		return (false);
	i = 0;
	while (i < value.length())
	{
		c = value[i];
		if (isAlphabetic(c))
		{
			i++;
			continue ;
		}
		if (c == ' ' || c == '-' || c == '\'')
		{
			if (i == 0 || i + 1 == value.length())
				return (false);
			if (!isAlphabetic(value[i - 1]) || !isAlphabetic(value[i + 1]))
				return (false);
		}
		else
			return (false);
		i++;
	}
	return (true);
}

bool PhoneBook::isPhoneNumberValid(const std::string& value)
{
	std::string::size_type	i;
	std::string::size_type	digit_count;

	if (value.length() < 3 || value[0] != '+')
		return (false);

	digit_count = value.length() - 1;
	if (digit_count < 2 || digit_count > 15)
		return (false);

	if (value[1] < '1' || value[1] > '9')
		return (false);

	i = 2;
	while (i < value.length())
	{
		if (std::isdigit(static_cast<unsigned char>(value[i])) == 0)
			return (false);
		i++;
	}
	return (true);
}

bool	PhoneBook::addContact(void)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	if (!readNameField("First name: ", firstName)
		|| !readNameField("Last name: ", lastName)
		|| !readRequiredField("Nickname: ", nickname)
		|| !readPhoneNumberField("Phone number: ", phoneNumber)
		|| !readRequiredField("Darkest secret: ", darkestSecret))
		return (false);
	_contacts[_nextIndex].set(firstName, lastName, nickname,
		phoneNumber, darkestSecret);
	_nextIndex = (_nextIndex + 1) % MAX_CONTACTS;
	if (_size < MAX_CONTACTS)
		_size++;
	std::cout << "Contact saved." << std::endl;
	return (true);
}

void	PhoneBook::printContactSummary(int index) const
{
	const Contact&	contact = _contacts[index];

	std::cout << std::setw(10) << index << "|"
		<< std::setw(10) << formatColumn(contact.getFirstName()) << "|"
		<< std::setw(10) << formatColumn(contact.getLastName()) << "|"
		<< std::setw(10) << formatColumn(contact.getNickname()) << std::endl;
}

void	PhoneBook::printContactDetails(int index) const
{
	const Contact&	contact = _contacts[index];

	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
}

void	PhoneBook::searchContacts(void) const
{
	std::string			line;
	std::stringstream	stream;
	int					index;
	char				extra;

	if (_size == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "index" << "|"
		<< std::setw(10) << "first name" << "|"
		<< std::setw(10) << "last name" << "|"
		<< std::setw(10) << "nickname" << std::endl;
	for (int i = 0; i < _size; i++)
		printContactSummary(i);
	std::cout << "Enter index: ";
	if (!std::getline(std::cin, line))
		return ;
	stream << line;
	if (!(stream >> index) || (stream >> extra) || index < 0 || index >= _size)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	if (!_contacts[index].isSet())
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	printContactDetails(index);
}
