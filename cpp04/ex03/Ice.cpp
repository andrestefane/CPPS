/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:24:41 by astefane          #+#    #+#             */
/*   Updated: 2026/01/21 14:53:14 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	
}

Ice::Ice(const Ice& other) : AMateria(other)
{

}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

Ice::~Ice()
{
	
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at "
              << target.getName()
              << " *" << std::endl;
}