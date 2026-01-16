/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:58:10 by astefane          #+#    #+#             */
/*   Updated: 2026/01/16 19:36:16 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
    brain = new Brain(*other.brain); 
    std::cout << "Copy Cat constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
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
