/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:56:23 by astefane          #+#    #+#             */
/*   Updated: 2026/01/09 12:56:25 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>

class Animal
{
    protected:
        std::string type;
    
    public:
        Animal();
        Animal::Animal(const Animal &other);
        Animal &Animal::operator=(const Animal &other);
        virtual ~Animal();
        
        std::string getType() const;
        virtual void   makeSound() const;
};

#endif