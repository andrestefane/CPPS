/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:57:16 by astefane          #+#    #+#             */
/*   Updated: 2026/01/23 14:46:59 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) 
{
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
   if (this != &other)
    {
        WrongCat::operator=(other);
        type = other.type;
    }
    return (*this);
}


WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Wrong Miau" << std::endl;
}
