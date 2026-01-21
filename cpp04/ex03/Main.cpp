/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:48:03 by astefane          #+#    #+#             */
/*   Updated: 2026/01/21 12:56:37 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
    IMateriaSource* src;
    ICharacter*     Carlos;
    ICharacter*     Juaquin;
    AMateria*      tmp;

    src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    Carlos = new Character("Carlos");

    tmp = src->createMateria("ice");
    Carlos->equip(tmp);
    tmp = src->createMateria("cure");
    Carlos->equip(tmp);

    Juaquin = new Character("Juaquin");

    Carlos->use(0, *Juaquin);
    Carlos->use(1, *Juaquin);

    delete Juaquin;
    delete Carlos;
    delete src;

    return 0;
}
