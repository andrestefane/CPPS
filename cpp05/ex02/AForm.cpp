/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:30:27 by astefane          #+#    #+#             */
/*   Updated: 2026/02/02 14:51:40 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gSign, int gExec)
:	_name(name), _signed(false), _gradeToSign(gSign),
	_gradeToExecute(gExec)
{
	if (gSign < 1 || gExec < 1)
		throw (GradeTooHighExpection());
	if (gSign > 150 || gExec > 150)
		throw (GradeTooLowExpection());
}

AForm::AForm(const AForm& other)
:	_name(other._name), _signed(other._signed),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute)
{
	
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

AForm::~AForm()
{
	
}

std::string AForm::getName() const
{
	return(_name);
}

bool	AForm::isSigned() const
{
	return (_signed);
}

int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
		throw (GradeTooHighExpection());
	_signed = true;
}

void	AForm::execute(Bureaucrat const& executor) const
{
	if (!_signed)
		throw (FormNotSignedExpection());
	if (executor.getGrade() > _gradeToExecute)
		throw (GradeTooLowExpection());
	executeAction();
}

const char* AForm::GradeTooHighExpection::what() const throw()
{
	return ("Grade too high");
}

const char* AForm::GradeTooLowExpection::what() const throw()
{
	return ("Grade too low");
}
const char* AForm::FormNotSignedExpection::what() const throw()
{
	return ("Form isn't signed");
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
	out << f.getName()
		<< ", Signed" << f.isSigned()
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute: " << f.getGradeToExecute();
	return (out);
}