/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:31:57 by astefane          #+#    #+#             */
/*   Updated: 2026/01/21 13:26:33 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria* _inventory[4];
public:
	Character(std::string const& name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	virtual ~Character();
	virtual std::string const& getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

};

#endif