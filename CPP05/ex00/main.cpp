#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	bureaucrat("John Doe", 0);
		std::cout << bureaucrat << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	bureaucrat("Jane Doe", 151);
		std::cout << bureaucrat << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	bureaucrat("Alice", 1);
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	bureaucrat("Bob", 150);
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}