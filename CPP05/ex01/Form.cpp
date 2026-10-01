#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: m_name("Unnamed"), m_signed(false), m_signGrade(150), m_executeGrade(150) {}

Form::Form(const std::string& name, int signGrade, int executeGrade)
	: m_name(name), m_signed(false), m_signGrade(signGrade), m_executeGrade(executeGrade)
{
	if (m_signGrade < 1 || m_executeGrade < 1)
		throw GradeTooHighException();
	if (m_signGrade > 150 || m_executeGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: m_name(other.m_name), m_signed(other.m_signed),
	  m_signGrade(other.m_signGrade), m_executeGrade(other.m_executeGrade) {}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		m_signed = other.m_signed;
	return *this;
}

Form::~Form() {}

const std::string&	Form::getName() const { return m_name; }

bool	Form::getSigned() const { return m_signed; }

int	Form::getSignGrade() const { return m_signGrade; }

int	Form::getExecuteGrade() const { return m_executeGrade; }

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > m_signGrade)
		throw GradeTooLowException();
	m_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream&	operator<<(std::ostream& out, const Form& form)
{
	out << form.getName()
		<< ", signed: " << (form.getSigned() ? "yes" : "no")
		<< ", signing grade: " << form.getSignGrade()
		<< ", execution grade: " << form.getExecuteGrade() << '.';
	return out;
}
