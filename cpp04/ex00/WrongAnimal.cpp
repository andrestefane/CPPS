/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:57:08 by astefane          #+#    #+#             */
/*   Updated: 2026/01/23 14:46:56 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    *this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
   if (this != &other)
    {
        WrongAnimal::operator=(other);
        type = other.type;
    }
    return (*this);
}


WrongAnimal::~WrongAnimal()
{
}

std::string WrongAnimal::getType() const
{
    return type;
}

void WrongAnimal::makeSound() const
{
}
