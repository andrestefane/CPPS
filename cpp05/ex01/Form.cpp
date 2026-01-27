/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:13:50 by astefane          #+#    #+#             */
/*   Updated: 2026/01/27 20:43:30 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
: name("DefaultForm"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	
}

Form::Form(const std::string& name, int gSign, int gExec)
: name(name), isSigned(false), gradeToSign(gSign), gradeToExecute(gExec)
{
	if (gSign < 1 || gExec < 1)
		throw GradeTooHighException();
	if (gSign > 150 || gExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
: 	name(other.name),
	isSigned(other.isSigned),
	gradeToSign(other.gradeToSign),
	gradeToExecute(other.gradeToExecute)
{
	
}

Form& Form::operator=(const Form&  other)
{
	if (this != &other)
		isSigned = other.isSigned;
	return (*this);
}

Form::~Form()
{
	
}

const std::string& Form::getName() const
{
	return (name);
}

bool	Form::getIsSigned() const
{
	return (isSigned);
}

int	Form::getGradeToSign() const
{
	return (gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (gradeToExecute);
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low");
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
	out << "Form " << f.getName()
		<< " Signed: " << (f.getIsSigned() ? "yes" : "no")
		<< ", gradeToSign: " << f.getGradeToExecute()
		<< ", gradeToExecute: " << f.getGradeToExecute();
	return (out);
}