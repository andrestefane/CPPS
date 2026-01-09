/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:46:13 by astefane          #+#    #+#             */
/*   Updated: 2026/01/07 11:58:56 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructed" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destroyed" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " can't attack" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name
				<< " attacks " << target 
				<< " ,causing " << _attackDamage 
				<< " dmg " << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " Is now in Guardian Mode " << std::endl;
}