/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:17:32 by astefane          #+#    #+#             */
/*   Updated: 2026/01/03 14:11:10 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"
#include <cmath>

/* Constructors */
fixed::fixed() : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

fixed::fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    _rawBits = n << _fractionalBits;
}

fixed::fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(f * (1 << _fractionalBits));
}

fixed::fixed(const fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

/* Operator = */
fixed& fixed::operator=(const fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _rawBits = other._rawBits;
    return (*this);
}

/* Destructor */
fixed::~fixed()
{
    std::cout << "Destructor called" << std::endl;
}

/* Getters / setters */
int fixed::getRawBits(void) const
{
    return (_rawBits);
}

void fixed::setRawBits(int const raw)
{
    _rawBits = raw;
}

/* Conversions */
float fixed::toFloat(void) const
{
    return ((float)_rawBits / (1 << _fractionalBits));
}

int fixed::toInt(void) const
{
    return (_rawBits >> _fractionalBits);
}

/* Operator << */
std::ostream& operator<<(std::ostream& out, const fixed& value)
{
    out << value.toFloat();
    return (out);
}
