/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:56:53 by astefane          #+#    #+#             */
/*   Updated: 2025/12/12 18:01:25 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#ifndef HUMANB_HPP
# define HUMANB_HPP

class HumanB
{
    private:
        std::string name;
        Weapon* weapon;
    public:
        HumanB(const std::string& n);
        ~HumanB();
        void setWeapon(Weapon& w);
        void attack() const;
};

#endif