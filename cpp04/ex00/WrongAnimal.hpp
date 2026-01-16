/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:57:13 by astefane          #+#    #+#             */
/*   Updated: 2026/01/09 12:57:14 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
    protected:
        std::string type;
    
    public:
	    WrongAnimal();
	    WrongAnimal(const WrongAnimal& other);
	    WrongAnimal& operator=(const WrongAnimal& other);
	    ~WrongAnimal();
	
	    void makeSound() const;
	    std::string getType() const;
};

#endif
