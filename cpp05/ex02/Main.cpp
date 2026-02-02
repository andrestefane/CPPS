/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:55:58 by astefane          #+#    #+#             */
/*   Updated: 2026/02/02 18:29:21 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"


int main()
{
    Bureaucrat boss("Boss", 1);
    ShrubberyCreationForm tree("home");

    boss.signForm(tree);
    boss.executeForm(tree);
	std::ifstream file("home_shrubbery");
	if (!file)
	{
	    std::cerr << "Error: couldn't open the Shrubbery archive" << std::endl;
	}
	else
	{
	    std::string line;
	    std::cout << "\n" << "================================" << "\n";
	    while (std::getline(file, line))
	        std::cout << line << std::endl;
	    std::cout << "\n" << "================================" << "\n";
	}

}
