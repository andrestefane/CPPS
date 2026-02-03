/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:55:58 by astefane          #+#    #+#             */
/*   Updated: 2026/02/03 19:17:18 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    std::srand(std::time(NULL));

    Bureaucrat boss("Boss", 1);
    Bureaucrat dude("Carlos", 150);

    Intern someIntern;
    AForm* forms[4];

    forms[0] = someIntern.makeForm("shrubbery creation", "home");
    forms[1] = someIntern.makeForm("robotomy request", "Bender");
    forms[2] = someIntern.makeForm("presidential pardon", "Marvin");

    forms[3] = someIntern.makeForm("fake form", "Nobody");

    std::cout << "\n";


    for (int i = 0; i < 3; ++i)
    {
        if (forms[i])
        {
            dude.signForm(*forms[i]);
            dude.executeForm(*forms[i]);
            std::cout << "\n";
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        if (forms[i])
        {
            boss.signForm(*forms[i]);
            boss.executeForm(*forms[i]);
            std::cout << "\n";
        }
    }
	
    std::ifstream file("home_shrubbery");
    if (file)
    {
        std::string line;
        std::cout << "=== Content of home_shrubbery ===\n";
        while (std::getline(file, line))
            std::cout << line << '\n';
        std::cout << "================================\n";
    }
    for (int i = 0; i < 4; ++i)
        delete forms[i];
    return (0);
}