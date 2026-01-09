/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:58:34 by astefane          #+#    #+#             */
/*   Updated: 2026/01/09 12:58:40 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();

    for (int i = 0; i < size; i++)
        delete animals[i];

    std::cout << "\n=== DEEP COPY TEST ===" << std::endl;

    Dog dog1;
    dog1.getBrain()->setIdea(0, "I want food");

    Dog dog2 = dog1; // COPY CONSTRUCTOR

    dog1.getBrain()->setIdea(0, "I want sleep");

    std::cout << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << dog2.getBrain()->getIdea(0) << std::endl;

    return 0;
}
