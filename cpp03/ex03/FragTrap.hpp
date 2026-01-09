/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:51:04 by astefane          #+#    #+#             */
/*   Updated: 2026/01/09 12:54:50 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"


class FragTrap : virtual public ClapTrap
{
    public:
		FragTrap(const std::string& name);
		~FragTrap();
		void	highFivesGuys(void);
};

#endif