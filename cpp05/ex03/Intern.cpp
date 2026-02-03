/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:47:09 by astefane          #+#    #+#             */
/*   Updated: 2026/02/03 19:13:59 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{	
}

Intern::Intern(const std::string& other)
{
	(void)other;
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern::~Intern()
{
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

static AForm* createShrubbery(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}

static AForm* createRobotomy(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}

static AForm* createPresidential(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    struct FormPair {
        std::string name;
        AForm* (*create)(const std::string&);
    };

   FormPair forms[] =
   {
    	{ "shrubbery creation", createShrubbery },
    	{ "robotomy request",   createRobotomy },
    	{ "presidential pardon",createPresidential }
	};

    for (int i = 0; i < 3; ++i)
    {
        if (forms[i].name == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (forms[i].create(target));
        }
    }

    std::cout << "Error: form \"" << formName << "\" does not exist" << std::endl;
    return (NULL);
}