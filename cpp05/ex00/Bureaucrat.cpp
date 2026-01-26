/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:25:44 by astefane          #+#    #+#             */
/*   Updated: 2026/01/26 18:36:00 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	
}

Bureaucrat::Bureaucrat(const std::string& _name, int _grade)
	:_name(_name), _grade(_grade)
{
	if (_grade < 1)
		throw (GradeTooHighException());
	if (_grade > 150)
		throw (GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade)
{

}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{

}

const std::string& Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::sumGrade(int sumeGrade)
{
	if (_grade - sumeGrade <= 1)
		throw (GradeTooHighException());
	_grade -= sumeGrade;
}

void	Bureaucrat::restGrade(int restGrade)
{
	if (_grade + restGrade > 150)
		throw (GradeTooLowException());
	_grade += restGrade;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw (GradeTooHighException());
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
	throw (GradeTooLowException());
	_grade++;
}

const	char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", Bureaucrat grade " << b.getGrade() << ".";
	return (out);
}