/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:38:07 by astefane          #+#    #+#             */
/*   Updated: 2026/01/07 13:11:48 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    std::cout << "CLAPTRAP TEST" << std::endl;

    ClapTrap clap("Clappy");

    clap.attack("Dummy");
    clap.takeDamage(3);
    clap.beRepaired(2);
    clap.takeDamage(20);
    clap.attack("Dummy");
    clap.beRepaired(5);

    std::cout << "SCAVTRAP TEST" << std::endl;

    ScavTrap scav("Scravy");

    scav.attack("Dummy");
    scav.takeDamage(30);
    scav.beRepaired(10);
    scav.guardGate();

    scav.attack("Dummy");

    scav.attack("Dummy");
    scav.beRepaired(5);

    return (0);
}
