#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	const int	signGrades[] = {0, 151, 1, 1};
	const int	executeGrades[] = {1, 1, 0, 151};
	for (int i = 0; i < 4; ++i)
	{
		try
		{
			Form	form("Invalid", signGrades[i], executeGrades[i]);
			std::cout << "Unexpected success: " << form << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\nSigning forms" << std::endl;
	Bureaucrat	alice("Alice", 50);
	Bureaucrat	bob("Bob", 51);
	Form		form("Leave request", 50, 25);
	std::cout << "Initially unsigned: " << form << std::endl;
	try
	{
		form.beSigned(bob);
		std::cout << "Unexpected success" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Expected Grade too low: " << e.what() << std::endl;
	}
	std::cout << "Still unsigned: " << form << std::endl;
	bob.signForm(form);
	std::cout << "Still unsigned after signForm: " << form << std::endl;
	alice.signForm(form);
	std::cout << "Signed at exact required grade: " << form << std::endl;

	std::cout << "\nSigning an already signed form" << std::endl;
	alice.signForm(form);
	bob.signForm(form);
	std::cout << "Remains signed: " << form << std::endl;

	std::cout << "\nValid grade boundaries and higher-ranked signer" << std::endl;
	Form		highest("Highest", 1, 1);
	Form		lowest("Lowest", 150, 150);
	Bureaucrat	chief("Chief", 1);
	Bureaucrat	junior("Junior", 150);
	chief.signForm(highest);
	junior.signForm(lowest);
	std::cout << highest << std::endl;
	std::cout << lowest << std::endl;
	Form		routine("Routine", 100, 75);
	chief.signForm(routine);
	std::cout << "Signed by a higher-ranked bureaucrat: " << routine << std::endl;

	std::cout << "\nDefault construction and copying" << std::endl;
	Form	assigned;
	std::cout << "Default (unsigned, grades 150): " << assigned << std::endl;
	Form	copy(form);
	std::cout << "Copy (same fields as Leave request): " << copy << std::endl;
	assigned = form;
	std::cout << "Assigned (signed, name and grades unchanged): " << assigned << std::endl;
	Form	unsignedForm("Unsigned", 100, 100);
	Form	unsignedCopy(unsignedForm);
	std::cout << "Unsigned copy: " << unsignedCopy << std::endl;
	assigned = unsignedForm;
	std::cout << "Assigned unsigned status: " << assigned << std::endl;
}
