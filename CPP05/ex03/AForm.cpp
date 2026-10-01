#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: m_name("Unnamed"), m_signed(false), m_signGrade(150), m_executeGrade(150) {}

AForm::AForm(const std::string& name, int signGrade, int executeGrade)
	: m_name(name), m_signed(false), m_signGrade(signGrade), m_executeGrade(executeGrade)
{
	if (m_signGrade < 1 || m_executeGrade < 1)
		throw GradeTooHighException();
	if (m_signGrade > 150 || m_executeGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: m_name(other.m_name), m_signed(other.m_signed),
	  m_signGrade(other.m_signGrade), m_executeGrade(other.m_executeGrade) {}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		m_signed = other.m_signed;
	return *this;
}

AForm::~AForm() {}

const std::string&	AForm::getName() const { return m_name; }

bool	AForm::getSigned() const { return m_signed; }

int	AForm::getSignGrade() const { return m_signGrade; }

int	AForm::getExecuteGrade() const { return m_executeGrade; }

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > m_signGrade)
		throw GradeTooLowException();
	m_signed = true;
}

void	AForm::execute(const Bureaucrat& executor) const
{
	if (!m_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > m_executeGrade)
		throw GradeTooLowException();
	executeAction();
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream&	operator<<(std::ostream& out, const AForm& form)
{
	out << form.getName()
		<< ", signed: " << (form.getSigned() ? "yes" : "no")
		<< ", signing grade: " << form.getSignGrade()
		<< ", execution grade: " << form.getExecuteGrade() << '.';
	return out;
}
