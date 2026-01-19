/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:48:03 by astefane          #+#    #+#             */
/*   Updated: 2026/01/19 19:06:28 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int	main()
{
	IMateriaSource*	src;
	ICharacter*		Carlos; // me
	AMateria*		tmp;
	ICharacter*		Juaquin; //bob
	AMateria*		saved;
	Character		Alice("Alice");
	Character		enemy("enemy");

	src = new MateriaSource();
	Carlos = new Character("Carlos");
	src->learMateria(new Ice());
	src->learMateria(new Cure());
	tmp = src->createMateria("Ice");
	Carlos->equip(tmp);
	tmp = src->createMateria("Cure");
	Carlos->equip(tmp);
	Juaquin = new Character("Juaquin");
	Carlos->use(0, *Juaquin);
	Carlos->use(1, *Juaquin);

	delete (Juaquin);
	delete (Carlos);
	delete (src);

	
}