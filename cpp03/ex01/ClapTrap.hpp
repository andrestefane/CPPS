/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:39:04 by astefane          #+#    #+#             */
/*   Updated: 2026/01/07 13:16:46 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
    protected:
	    std::string		_name;
	    unsigned int	_hitPoints;
	    unsigned int	_energyPoints;
	    unsigned int	_attackDamage;
	
    public:
		ClapTrap(const std::string name);
		~ClapTrap();
        void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
#endif