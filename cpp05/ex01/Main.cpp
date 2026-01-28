/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:55:58 by astefane          #+#    #+#             */
/*   Updated: 2026/01/28 18:02:46 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cctype>
#include <cstdlib>


int main()
{
	Bureaucrat	A("Andrei", 2);
	Bureaucrat	B("Carlos", 20);
	Form	Agent("Monday", 2, 2);
	Form	Secret("Something", 25, 1);
	std::cout << "================================" << std::endl;
	B.signForm(Agent);
	std::cout << '\n';
	B.signForm(Secret);
	std::cout << '\n';


	std::cout << Agent << '\n';
	std::cout << '\n';
	std::cout << Secret << std::endl;
	std::cout << '\n';

	A.signForm(Agent);
	std::cout << '\n';
	std::cout << Agent << std::endl;
	std::cout << "================================" << std::endl;
    return (0);
}
