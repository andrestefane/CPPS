/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:55:58 by astefane          #+#    #+#             */
/*   Updated: 2026/01/27 17:04:43 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cctype>
#include <cstdlib>

bool isEmpty(const std::string &s)
{
    return (s.empty());
}

bool digits(const std::string &s)
{
    if (s.empty())
        return (false);

    for (size_t i = 0; i < s.length(); i++)
    {
        if (!std::isdigit(s[i]))
            return (false);
    }
    return (true);
}

int main()
{
	std::string line;
	std::string line2;
	std::string strlvl2;
	std::string strlvl;
	std::string	strnumber;
	int			number = 0;
	int			lvl = 0;
	int			lvl2 = 0;
	
	Bureaucrat* a = NULL;
	Bureaucrat* b = NULL;
	std::cout << "Insert name of first bureaucrat" << std::endl;
	std::getline(std::cin, line);
	std::cout << "Insert lvl of first bureaucrat" << std::endl;
	std::getline(std::cin, strlvl);
	lvl = atoi(strlvl.c_str());
	if (isdigit(lvl))
	{
		std::cout << "Expected a number" << std::endl;
		return (0);
	}
	std::cout << "Insert name of second bureaucrat" << std::endl;
	std::getline(std::cin, line2);
	std::cout << "Insert lvl of second bureaucrat" << std::endl;
	std::getline(std::cin, strlvl2);
	lvl2 = atoi(strlvl2.c_str());
	if (isdigit(lvl2))
	{
		std::cout << "Expected a number" << std::endl;
		return (0);
	}
	
	if (isEmpty(line) && isEmpty(line2))
	{
		try
		{
			Bureaucrat a("Andrei", 2);
			std::cout << a << std::endl;
			a.incrementGrade();
			std::cout << a << std::endl;
			a.incrementGrade();
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			Bureaucrat b("Carlos", 151);
		}
		catch(const std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
		return (0);
	}
	else
	{
		try
		{
			a = new Bureaucrat(line, lvl);	
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << "How much want it to increment first bureaucrat?" << std::endl;
		std::getline(std::cin, strnumber);
		if (isEmpty(strnumber))
		{
			delete a;
			return (0);
		}
		number = atoi(strnumber.c_str());
		if (isdigit(number))
		{
			std::cout << "Expected a number" << std::endl;
			delete a;
			return (0);
		}
		try
		{
			a->sumGrade(number);
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
		




		try
		{
			b = new Bureaucrat(line2, lvl2);
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << "How much want it to increment second bureaucrat?" << std::endl;
		std::getline(std::cin, strnumber);
		number = atoi(strnumber.c_str());
		if (isdigit(number))
		{
			std::cout << "Expected a number" << std::endl;
			delete b;
			return (0);
		}
		try
		{
			b->restGrade(number);
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << "Grade of:" << a->getName() << " now is " << a->getGrade() << std::endl;
	std::cout << "Grade of:" << b->getName() << " now is " << b->getGrade() << std::endl;
	delete a;
	delete b;
	return (0);
}

/* int	main()
{
	try
	{
		Bureaucrat a("Andrei", 2);
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		a.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat b("Carlos", 151);
	}
	catch(std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
} */