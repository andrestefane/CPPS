/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:58:10 by astefane          #+#    #+#             */
/*   Updated: 2026/01/23 14:35:40 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
    brain = new Brain(*other.brain); 
}

Cat &Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        AAnimal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return (*this);
}

Cat::~Cat()
{
    delete (brain);
    std::cout << "Cat destructor called" << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << "Miau" << std::endl;
}

const Brain* Cat::getBrain() const
{
    return (brain);
}
