/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:17:32 by astefane          #+#    #+#             */
/*   Updated: 2025/12/26 18:18:32 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"
# include <cmath>


fixed::fixed() : _rawBits()
{
	std::cout << "Default constructor calle" << '\n';
}

fixed::fixed(const int n)
{
    std::cout << "Int constructor called" << '\n';
    _rawBits = n << _fractionalBits;
}

fixed::fixed(const float f)
{
    std::cout << "Float constructor called" << '\n';
    _rawBits = roundf(f * (1 << _fractionalBits));
}

fixed::fixed(const fixed &other)
{
	std::cout << "Copy constructor called" << '\n';
	*this = other;
}

fixed &fixed::operator=(const fixed &other)
{
	std::cout << "Copy assigment operator called" << '\n';
	if (this != &other)
		this->_rawBits = other._rawBits;
	return (*this);
}

fixed::~fixed()
{
	std::cout << "Destructor called" << '\n';	
}

int	fixed::getRawBits(void) const
{
	std::cout << "getRawBits member fuction called" << '\n';
	return (this->_rawBits);
}

void	fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}