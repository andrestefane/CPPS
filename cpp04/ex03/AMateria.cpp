/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:46:08 by astefane          #+#    #+#             */
/*   Updated: 2026/01/21 14:50:22 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "Costructor called" << std::endl;

}

AMateria::AMateria(const AMateria &other) : _type(other._type)
{

}

AMateria&  AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "Destructor called" << std::endl;

}

std::string const& AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}