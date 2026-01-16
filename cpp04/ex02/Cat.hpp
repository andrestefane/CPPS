/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:58:17 by astefane          #+#    #+#             */
/*   Updated: 2026/01/16 19:05:43 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"
# include "AAnimal.hpp"

class Cat : public AAnimal
{
    private:
        Brain* brain;
    public:
        Cat();
    	Cat &operator=(const Cat &other);
        Cat(const Cat &other);
        ~Cat();

        void    makeSound() const;
        const Brain* getBrain() const;
    };

#endif