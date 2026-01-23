/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:57:30 by astefane          #+#    #+#             */
/*   Updated: 2026/01/21 19:09:40 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"

Animal::Animal() : type ("Animal")
{
}

Animal::Animal(const Animal& other) : type(other.type)
{
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        type = other.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return (type);
}

void    Animal::makeSound() const
{
    std::cout << " Animal Sound " << std::endl;
}
