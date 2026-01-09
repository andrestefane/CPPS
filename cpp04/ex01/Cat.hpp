/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:58:17 by astefane          #+#    #+#             */
/*   Updated: 2026/01/09 12:58:21 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain* brain;
    public:
        Cat();
        ~Cat();
        Cat&    operator=(const Cat& other);
        void    makeSound() const;
        Brain* getbBrain() const;
    };

#endif