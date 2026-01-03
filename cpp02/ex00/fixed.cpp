/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:17:32 by astefane          #+#    #+#             */
/*   Updated: 2026/01/03 09:37:00 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

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
