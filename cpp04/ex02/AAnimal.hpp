/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:14:38 by andres            #+#    #+#             */
/*   Updated: 2026/01/16 17:21:15 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <iostream>
# include <string>

class AAnimal
{
	protected:
		AAnimal();
		std::string type;
		
	public:
		AAnimal(const AAnimal& other);
        AAnimal& operator=(const AAnimal& other);
		virtual ~AAnimal();

		virtual void	makeSound() const;
		std::string		getType() const;
};

#endif