/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:55:58 by astefane          #+#    #+#             */
/*   Updated: 2026/01/27 20:58:00 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cctype>
#include <cstdlib>

int main()
{
    Bureaucrat bob("Bob", 50);
    Bureaucrat alice("Alice", 1);

    Form tax("TaxForm", 40, 20);
    Form secret("SecretForm", 1, 1);

    std::cout << tax << std::endl;

    bob.signForm(tax);
    alice.signForm(tax);
    alice.signForm(secret);
    bob.signForm(secret);

    std::cout << tax << std::endl;
    std::cout << secret << std::endl;

    return 0;
}