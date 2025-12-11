/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 22:16:36 by astefane          #+#    #+#             */
/*   Updated: 2025/12/11 19:33:37 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name);

int main()
{
    std::cout << " Insert number to create the horde: ";
    int 	number;
    Zombie*	horde;

    number = 0;
    if (!(std::cin >> number))
	{
		std::cout << "Is not a number try again" << '\n';
		return 1;
	}
	horde = zombieHorde(number, "Andrei");
	for (int i = 0; i < number; i++)
    	horde[i].announce();

	delete[] horde;
    return (0);
}
