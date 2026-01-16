/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:58:24 by astefane          #+#    #+#             */
/*   Updated: 2026/01/16 19:40:44 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    brain = new Brain(*other.brain); 
    std::cout << "Copy Dog constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
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
