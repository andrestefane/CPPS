/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:00:14 by astefane          #+#    #+#             */
/*   Updated: 2025/12/12 18:08:25 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& n) : name(n), weapon(NULL)
{
}
HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon& w)
{
    weapon = &w;
}

void HumanB::attack() const
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << '\n';
    else
        std::cout << name << " has no weapon to attack " << '\n';
}