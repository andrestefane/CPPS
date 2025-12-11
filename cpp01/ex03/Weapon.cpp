/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:49:32 by astefane          #+#    #+#             */
/*   Updated: 2025/12/11 20:52:19 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& t) : type(t)
{  
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType() const
{
	return (type);	
}

void Weapon::setType(const std::string& newType)
{
	type = newType;
}
