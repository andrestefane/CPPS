/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:58:29 by astefane          #+#    #+#             */
/*   Updated: 2026/01/16 17:30:07 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"
# include "AAnimal.hpp"

class Dog : public Animal, public AAnimal
{
    private:
        Brain* brain;
    public:
        Dog();
    	Dog&operator=(const Dog &other);
        Dog(const Dog &other);
        ~Dog();

        void    makeSound() const override;
        const Brain* getBrain() const;
    };

#endif