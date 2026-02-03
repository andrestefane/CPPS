/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:55:58 by astefane          #+#    #+#             */
/*   Updated: 2026/02/03 18:21:05 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"


int main()
{
	std::srand(std::time(NULL));
    Bureaucrat boss("Boss", 1);
	Bureaucrat dude("Pablo", 146);
    ShrubberyCreationForm tree("home");
	RobotomyRequestForm robot("robot");
	PresidentialPardonForm pardon("Carlos");

	dude.signForm(tree);
	dude.executeForm(tree);
	std::cout << std::endl;
	std::cout << std::endl;
	dude.signForm(robot);
	dude.executeForm(robot);
	std::cout << std::endl;
	std::cout << std::endl;
	dude.signForm(pardon);
	dude.executeForm(pardon);
	std::cout << std::endl;
	std::cout << std::endl;


	
    boss.signForm(tree);
	boss.signForm(pardon);
	boss.signForm(robot);
    boss.executeForm(tree);
	
	std::ifstream file("home_shrubbery");
	if (!file)
	    std::cerr << "Error: couldn't open the Shrubbery archive" << std::endl;
	else
	{
	    std::string line;
	    std::cout << "\n" << "================================" << "\n";
	    while (std::getline(file, line))
	        std::cout << line << std::endl;
	    std::cout << "\n" << "================================" << "\n";
	}
	std::cout << std::endl;
	boss.executeForm(robot);
	std::cout << std::endl;
	boss.executeForm(pardon);
	std::cout << std::endl;

	dude.executeForm(tree);
	dude.executeForm(robot);
	dude.executeForm(pardon);
	std::cout << std::endl;

	std::cout << tree << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;
	return (0);
}
