/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:38:07 by astefane          #+#    #+#             */
/*   Updated: 2026/01/10 15:04:42 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "CLAPTRAP" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("Target");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\nSCAVTRAP" << std::endl;
    ScavTrap scav("Scavy");
    scav.attack("Target");
    scav.guardGate();

    std::cout << "\nFRAGTRAP" << std::endl;
    FragTrap frag("Fraggy");
    frag.attack("Target");
    frag.highFivesGuys();

    return (0);
}
