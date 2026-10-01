#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("Unnamed"), m_grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: m_name(name), m_grade(grade)
{
	if (m_grade < 1)
		throw GradeTooHighException();
	if (m_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: m_name(other.m_name), m_grade(other.m_grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this !=& other)
		m_grade = other.m_grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string	&Bureaucrat::getName() const { return m_name; }

int	Bureaucrat::getGrade() const { return m_grade; }

void	Bureaucrat::incrementGrade()
{
	if (m_grade <= 1)
		throw GradeTooHighException();
	m_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (m_grade >= 150)
		throw GradeTooLowException();
	++m_grade;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName()
		<< ", bureaucrat grade " << bureaucrat.getGrade() << '.';
	return out;
}
