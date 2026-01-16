/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:57:25 by astefane          #+#    #+#             */
/*   Updated: 2026/01/09 12:57:26 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
	    WrongCat();
	    WrongCat(const WrongCat& other);
	    WrongCat& operator=(const WrongCat& other);
	    ~WrongCat();
	
	    void makeSound() const;
};

#endif
