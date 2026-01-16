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
#include "WrongCat.hpp"


int main()
{
    std::cout << "===== ANIMAL TEST =====" << std::endl;

    Animal* animals[6];

    for (int i = 0; i < 3; i++)
        animals[i] = new Dog();

    for (int i = 3; i < 6; i++)
        animals[i] = new Cat();

    for (int i = 0; i < 6; i++)
        animals[i]->makeSound();

    Dog dog1;
    Dog dog2 = dog1;

    dog2.makeSound();

    Cat cat1;
    Cat cat2;
    cat2 = cat1;
    cat2.makeSound();


    std::cout << "Dog1 Brain: " << dog1.getBrain() << std::endl;
    std::cout << "Dog2 Brain: " << dog2.getBrain() << std::endl;

    std::cout << "Cat1 Brain: " << cat1.getBrain() << std::endl;
    std::cout << "Cat2 Brain: " << cat2.getBrain() << std::endl;


    for (int i = 0; i < 6; i++)
        delete animals[i];

    std::cout << "\n===== WRONG ANIMAL TEST =====" << std::endl;

    WrongAnimal* wrong = new WrongCat();
    wrong->makeSound();
    delete wrong;

    return (0);
}