/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:15:41 by astefane          #+#    #+#             */
/*   Updated: 2026/01/16 17:22:15 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Unkown")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
    std::cout << "AAnimal copy assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return (*this);
}

std::string AAnimal::getType() const
{
    return (type);
}

void    AAnimal::makeSound() const
{
    std::cout << " AAnimal Sound " << std::endl;
}
