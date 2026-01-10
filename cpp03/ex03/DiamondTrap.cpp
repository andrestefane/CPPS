/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:41:04 by astefane          #+#    #+#             */
/*   Updated: 2026/01/10 15:10:06 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("default_clap_name"),
      ScavTrap("default"),
      FragTrap("default"),
      _name("default")
{
    _hitPoints = FragTrap::_hitPoints;        // 100
    _energyPoints = ScavTrap::_energyPoints;  // 50
    _attackDamage = FragTrap::_attackDamage;  // 30

    std::cout << "DiamondTrap default constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"),
      ScavTrap(name),
      FragTrap(name),
      _name(name)
{
    _hitPoints = FragTrap::_hitPoints;        // 100
    _energyPoints = ScavTrap::_energyPoints;  // 50
    _attackDamage = FragTrap::_attackDamage;  // 30

    std::cout << "DiamondTrap " << _name << " constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other),
      ScavTrap(other),
      FragTrap(other),
      _name(other._name)
{
    std::cout << "DiamondTrap copy constructed" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " destroyed" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        _name = other._name;
    }
    return *this;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << _name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}

void DiamondTrap::showStats() const
{
    std::cout << "=== " << _name << " STATS ===" << std::endl;
    std::cout << "Hit Points    : " << _hitPoints << std::endl;
    std::cout << "Energy Points : " << _energyPoints << std::endl;
    std::cout << "Attack Damage : " << _attackDamage << std::endl;
}
