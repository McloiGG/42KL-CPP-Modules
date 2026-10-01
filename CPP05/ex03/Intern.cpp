#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstddef>
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern() {}

static AForm*	createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

static AForm*	createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static AForm*	createPardon(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target) const
{
	typedef AForm*	(*FormCreator)(const std::string&);

	const std::string	names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	const FormCreator	creators[] = {createShrubbery, createRobotomy, createPardon};

	for (int i = 0; i < 3; ++i)
	{
		if (name == names[i])
		{
			AForm*	form = creators[i](target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}
	std::cout << "Intern couldn't create form: unknown form name \"" << name << '"' << std::endl;
	return NULL;
}
