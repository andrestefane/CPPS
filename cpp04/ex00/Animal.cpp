/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:56:13 by astefane          #+#    #+#             */
/*   Updated: 2026/01/09 12:56:16 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type ("Animal")
{
    std::cout << "Animal Constructor called" << std::endl;
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
    std::cout << "Animal Sound " << std::endl;
}
