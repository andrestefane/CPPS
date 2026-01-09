/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:38:07 by astefane          #+#    #+#             */
/*   Updated: 2026/01/05 18:41:53 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Andrei");

    a.attack("enemy");
    a.takeDamage(5);
    a.beRepaired(3);
    a.attack("enemy");
    a.takeDamage(20);
    a.attack("enemy");

    return (0);
}