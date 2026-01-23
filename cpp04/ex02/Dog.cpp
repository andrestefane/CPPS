/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:58:24 by astefane          #+#    #+#             */
/*   Updated: 2026/01/23 14:35:48 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
    brain = new Brain(*other.brain); 
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        AAnimal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return (*this);
}

Dog::~Dog()
{
    delete (brain);
    std::cout << "Dog destructor called" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "Guau" << std::endl;
}

const Brain* Dog::getBrain() const
{
    return (brain);
}
