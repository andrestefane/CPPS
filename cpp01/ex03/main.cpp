/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:04:41 by astefane          #+#    #+#             */
/*   Updated: 2025/12/15 20:37:42 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "HumanA.hpp"

bool is_empty(const std::string &s)
{
    return (s.empty());
}
int main() {
    std::string line, PJ1, PJ2, WeaponA, WeaponB;

    // Declaramos punteros antes del if para que existan en todo el main
    Weapon* clubA = NULL;
    HumanA* bob1 = NULL;

    Weapon* clubB = NULL;
    HumanB* bob2 = NULL;

    std::cout << "Insert 'A' to start with humanA: " << std::endl;
    std::getline(std::cin, line);
    if (is_empty(line))
    {
        std::cout << "Please select a weapon for any human" << std::endl;
        return (1);
    }
    if (line == "A" || line == "HumanA" || line == "humanA" || line == "a")
    {
        std::cout << "Specify the weapon: " << std::endl;
        std::getline(std::cin, WeaponA);
        if (is_empty(WeaponA))
        {
            std::cout << "HumanA has to have a weapon" << std::endl;
            return (1);
        }
        std::cout << "The weapon for HumanA is: " << WeaponA << std::endl;
        std::cout << "Which is the name of HumanA ? " << std::endl;
        std::getline(std::cin, PJ1);
        std::cout << "The name of first human is: " << PJ1 << std::endl;
        clubA = new Weapon(WeaponA);
        if (is_empty(PJ1))
            PJ1 = "Bob1";
        bob1 = new HumanA(PJ1, *clubA);
    }
    std::cout << "Insert 'B' to start with humanB " << std::endl;
    std::getline(std::cin, line);
    if (line == "B" || line == "HumanB" || line == "humanB" || line == "b")
    {
        std::cout << "Specify the weapon: " << std::endl;
        std::getline(std::cin, WeaponB);
        std::cout << "The weapon for HumanB is: " << WeaponB << std::endl;
        std::cout << "Which is the name of HumanB? " << std::endl;
        std::getline(std::cin, PJ2);
        std::cout << "The name of second human is: " << PJ2 << std::endl;
        clubB = new Weapon(WeaponB);
        if (is_empty(PJ2))
            PJ2 = "Bob2";
        bob2 = new HumanB(PJ2);
        if (!is_empty(WeaponB))
            bob2->setWeapon(*clubB);
    }
    else if (line != "B" || line != "HumanB" || line != "humanB" || line != "b")
    {
        PJ2 = "bob2";
        bob2 = new HumanB(PJ2);
    }
    if (bob1)
        bob1->attack();
    if (bob2)
        bob2->attack();
    if (bob1 && clubA)
        clubA->setType(WeaponA);
    if (bob1)
        bob1->attack();
    if (bob2 && clubB)
        clubB->setType(WeaponB);
    if (bob2)
        bob2->attack();
    delete (bob1);
    delete (clubA);
    delete (bob2);
    delete (clubB);
    return (0);
}
