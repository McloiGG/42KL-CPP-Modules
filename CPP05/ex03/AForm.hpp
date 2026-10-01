#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
private:
	const std::string	m_name;
	bool				m_signed;
	const int			m_signGrade;
	const int			m_executeGrade;

	virtual void	executeAction() const = 0;

public:
	AForm();
	AForm(const std::string& name, int signGrade, int executeGrade);
	AForm(const AForm& other);
	AForm&	operator=(const AForm& other);
	virtual ~AForm();

	const std::string&	getName() const;
	bool				getSigned() const;
	int					getSignGrade() const;
	int					getExecuteGrade() const;

	void				beSigned(const Bureaucrat& bureaucrat);
	void				execute(const Bureaucrat& executor) const;

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& out, const AForm& form);

#endif
