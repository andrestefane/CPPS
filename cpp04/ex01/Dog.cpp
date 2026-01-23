/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:58:24 by astefane          #+#    #+#             */
/*   Updated: 2026/01/21 19:11:34 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
    brain = new Brain(*other.brain); 
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return (*this);
}

Dog::~Dog()
{
    delete (brain);
}

void    Dog::makeSound() const
{
    std::cout << "Guau" << std::endl;
}

const Brain* Dog::getBrain() const
{
    return (brain);
}
