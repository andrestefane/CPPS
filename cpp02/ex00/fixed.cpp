/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:17:32 by astefane          #+#    #+#             */
/*   Updated: 2026/01/03 14:08:08 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

fixed::fixed() : _rawBits(7)
{
    std::cout << "Default constructor called" << std::endl;
}

fixed::fixed(const fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

fixed &fixed::operator=(const fixed &other)
{
    std::cout << "Copy assigment operator called" << std::endl;
    if (this != &other)
        this->_rawBits = other._rawBits;
    return (*this);
}

fixed::~fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_rawBits);
}

void fixed::setRawBits(int const raw)
{
    this->_rawBits = raw;
}
