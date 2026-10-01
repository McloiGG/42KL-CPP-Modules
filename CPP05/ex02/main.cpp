#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>

void	testExecution(AForm& form)
{
	Bureaucrat	signer("Signer", form.getSignGrade());
	Bureaucrat	executor("Executor", form.getExecuteGrade());
	Bureaucrat	tooLow("Too low", form.getExecuteGrade() + 1);

	std::cout << '\n' << form << std::endl;
	std::cout << "Unsigned execution: expect Form is not signed" << std::endl;
	try
	{
		form.execute(executor);
		std::cout << "Unexpected success" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	executor.executeForm(form);
	signer.signForm(form);
	std::cout << "Signed execution with insufficient grade: expect Grade too low" << std::endl;
	try
	{
		form.execute(tooLow);
		std::cout << "Unexpected success" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	tooLow.executeForm(form);
	std::cout << "Execution at exact required grade: expect action" << std::endl;
	executor.executeForm(form);
}

int	main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	Bureaucrat				chief("Chief", 1);
	ShrubberyCreationForm	shrubbery("home");
	RobotomyRequestForm		robotomy("Bender");
	PresidentialPardonForm	pardon("Arthur Dent");

	testExecution(shrubbery);
	testExecution(robotomy);
	testExecution(pardon);

	std::cout << "\nShrubbery file contents (expect an ASCII tree)" << std::endl;
	std::ifstream	file("home_shrubbery");
	std::string		line;
	if (!file)
		std::cout << "Unexpected failure: cannot read home_shrubbery" << std::endl;
	while (std::getline(file, line))
		std::cout << line << std::endl;
	file.close();

	std::cout << "\nRepeated robotomy (each attempt has a 50% success chance)" << std::endl;
	for (int i = 0; i < 10; ++i)
		chief.executeForm(robotomy);

	std::cout << "\nDerived form copies (expect original targets and signed status)" << std::endl;
	ShrubberyCreationForm	shrubberyCopy(shrubbery);
	RobotomyRequestForm		robotomyCopy(robotomy);
	PresidentialPardonForm	pardonCopy(pardon);
	chief.executeForm(shrubberyCopy);
	chief.executeForm(robotomyCopy);
	chief.executeForm(pardonCopy);

	std::cout << "\nDefault forms (expect unsigned and fixed required grades)" << std::endl;
	ShrubberyCreationForm	shrubberyAssigned;
	RobotomyRequestForm		robotomyAssigned;
	PresidentialPardonForm	pardonAssigned;
	std::cout << shrubberyAssigned << std::endl;
	std::cout << robotomyAssigned << std::endl;
	std::cout << pardonAssigned << std::endl;

	std::cout << "\nDerived assignment (expect original targets and signed status)" << std::endl;
	shrubberyAssigned = shrubbery;
	robotomyAssigned = robotomy;
	pardonAssigned = pardon;
	chief.executeForm(shrubberyAssigned);
	chief.executeForm(robotomyAssigned);
	chief.executeForm(pardonAssigned);

	std::cout << "\nPolymorphic execution and deletion" << std::endl;
	AForm*	form = new PresidentialPardonForm("Ford Prefect");
	chief.signForm(*form);
	chief.executeForm(*form);
	delete form;

	std::cout << "\nFile error (home_shrubbery is a file, not a directory)" << std::endl;
	ShrubberyCreationForm	invalidPath("home_shrubbery/tree");
	chief.signForm(invalidPath);
	chief.executeForm(invalidPath);
}
