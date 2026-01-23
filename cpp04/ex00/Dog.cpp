/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:56:43 by astefane          #+#    #+#             */
/*   Updated: 2026/01/23 14:46:40 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other)
{
    *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
   if (this != &other)
    {
        Dog::operator=(other);
        type = other.type;
    }
    return (*this);
}


Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "Guau" << std::endl;
}
