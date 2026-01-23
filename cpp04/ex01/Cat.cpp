/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:58:10 by astefane          #+#    #+#             */
/*   Updated: 2026/01/21 19:11:38 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
    brain = new Brain(*other.brain); 
}

Cat &Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return (*this);
}

Cat::~Cat()
{
    delete (brain);
}

void    Cat::makeSound() const
{
    std::cout << "Miau" << std::endl;
}

const Brain* Cat::getBrain() const
{
    return (brain);
}
