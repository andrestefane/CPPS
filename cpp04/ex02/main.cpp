/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:58:34 by astefane          #+#    #+#             */
/*   Updated: 2026/01/23 14:36:12 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"


/* class TestAnimal : public AAnimal {
public:
    TestAnimal() { type = "TestAnimal"; }
    void makeSound() const { std::cout << "Test sound!" << std::endl; }
}; */
int main()
{
    /* TestAnimal a;
    a.makeSound(); */

    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();

    std::cout << std::endl;

    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;

    std::cout << std::endl;

    dog->makeSound();
    cat->makeSound();

    std::cout << std::endl;

    delete dog;
    delete cat;

    return (0);
}