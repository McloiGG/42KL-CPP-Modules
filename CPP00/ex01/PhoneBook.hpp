#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# include <string>

class PhoneBook
{
private:
	static const int	MAX_CONTACTS = 8;

	Contact	_contacts[MAX_CONTACTS];
	int		_size;
	int		_nextIndex;

	static std::string	formatColumn(const std::string& text);
	static bool			readRequiredField(const std::string& label,
							std::string& value);
	static bool			readNameField(const std::string& label,
							std::string& value);
	static bool			readPhoneNumberField(const std::string& label,
							std::string& value);
	static bool			isNameValid(const std::string& value);
	static bool			isPhoneNumberValid(const std::string& value);
	static bool			isAlphabetic(char c);
	void				printContactSummary(int index) const;
	void				printContactDetails(int index) const;

public:
	PhoneBook(void);

	bool	addContact(void);
	void	searchContacts(void) const;
};

#endif
