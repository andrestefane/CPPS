/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:56:43 by astefane          #+#    #+#             */
/*   Updated: 2026/01/09 12:56:45 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Copy Dog constructor called" << std::endl;
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
