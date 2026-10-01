#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

void	testCreation(const Intern& intern, const std::string& name, const std::string& target)
{
	Bureaucrat	chief("Chief", 1);
	AForm*		form = intern.makeForm(name, target);

	if (!form)
	{
		std::cout << "Unexpected failure: form was not created" << std::endl;
		return;
	}
	std::cout << "New form (expect unsigned): " << *form << std::endl;
	std::cout << "Expected target: " << target << std::endl;
	chief.signForm(*form);
	chief.executeForm(*form);
	delete form;
}

int	main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	Intern	intern;

	std::cout << "\nCreating each supported form" << std::endl;
	testCreation(intern, "shrubbery creation", "garden");
	testCreation(intern, "robotomy request", "Bender");
	testCreation(intern, "presidential pardon", "Arthur Dent");

	std::cout << "\nUnknown names (expect an error and a null pointer)" << std::endl;
	const std::string	names[] = {"coffee request", "", "Robotomy Request"};
	for (int i = 0; i < 3; ++i)
	{
		AForm*	form = intern.makeForm(names[i], "Nobody");
		if (!form)
			std::cout << "No form returned, as expected" << std::endl;
		else
			std::cout << "Unexpected success: " << *form << std::endl;
		delete form;
	}

	std::cout << "\nRepeated creation (expect independent forms and targets)" << std::endl;
	Bureaucrat	chief("Chief", 1);
	AForm*		first = intern.makeForm("presidential pardon", "Trillian");
	AForm*		second = intern.makeForm("presidential pardon", "Ford Prefect");
	if (first && second)
	{
		chief.signForm(*first);
		std::cout << "First should be signed: " << *first << std::endl;
		std::cout << "Second should still be unsigned: " << *second << std::endl;
		chief.signForm(*second);
		chief.executeForm(*first);
		chief.executeForm(*second);
	}
	else
		std::cout << "Unexpected failure: form was not created" << std::endl;
	delete first;
	delete second;

	std::cout << "\nCopied and assigned interns can still create forms" << std::endl;
	Intern	copy(intern);
	Intern	assigned;
	assigned = intern;
	testCreation(copy, "presidential pardon", "Copied intern target");
	testCreation(assigned, "presidential pardon", "Assigned intern target");
}
