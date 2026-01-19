/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:31:57 by astefane          #+#    #+#             */
/*   Updated: 2026/01/19 15:33:37 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
#include "ICharacter.hpp"

class Character
{
private:
	std::string _name;
	AMateria* _inventory[4];
public:
	Character(std::string const& name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	virtual ~Character();
	std::string const& Character::getName() const;
	void	Character::equip(AMateria* m);
	void	Character::unequip(int idx);
	void	Character::use(int idx, ICharacter& target);

};

#endif