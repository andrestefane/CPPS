/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:56:29 by astefane          #+#    #+#             */
/*   Updated: 2026/01/09 12:56:33 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Copy Cat constructor called" << std::endl;
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
   if (this != &other)
    {
        Cat::operator=(other);
        type = other.type;
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << "Meaow" << std::endl;
}
