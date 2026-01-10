/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:38:07 by astefane          #+#    #+#             */
/*   Updated: 2026/01/10 15:11:18 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap d("Guardian");
    std::cout << "\n";
    d.showStats();
    d.whoAmI();
    std::cout << "\n";
    std::cout << "\n";
    d.attack("Bandit");
    DiamondTrap copy(d);
    std::cout << "\n";
    copy.showStats();
    copy.whoAmI();
    std::cout << "\n";
    std::cout << "\n";
    copy.attack("Copy enemy");
    DiamondTrap assign;
    assign = d;
    std::cout << "\n";
    assign.showStats();
    assign.whoAmI();
    std::cout << "\n";
    std::cout << "\n";
    assign.attack("Assigned enemy");
    return (0);
}
