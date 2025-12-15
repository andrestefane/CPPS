/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:14:00 by astefane          #+#    #+#             */
/*   Updated: 2025/12/15 19:41:03 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#ifndef HUMANA_HPP
# define HUMANA_HOO

class HumanA
{
private:
    std::string name;
    Weapon& weapon;

public:
    HumanA(const std::string& n, Weapon& w);
    ~HumanA();

    void attack() const;
};

#endif
