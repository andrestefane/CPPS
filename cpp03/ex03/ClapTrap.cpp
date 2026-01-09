/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:59:23 by astefane          #+#    #+#             */
/*   Updated: 2026/01/07 12:28:39 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructed" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroyed" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name
				<< " attacks " << target 
				<< " ,causing " << _attackDamage 
				<< " dmg " << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap" << _name << " don't have enough hitpoints" << std::endl;
		return ;
	}
	_hitPoints -= amount;
	if (_hitPoints <= 0)
	{
		_hitPoints = 0;
	}

	std::cout << "ClapTrap " << _name
              << " takes " << amount
              << " points of damage" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "ClapTrap" << _name << " can't be repaired" << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name
              << " repairs itself for "
              << amount << " hit points" << std::endl;
}
