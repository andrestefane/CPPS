/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:46:08 by astefane          #+#    #+#             */
/*   Updated: 2025/12/26 15:46:36 by astefane         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include "fixed.hpp"

int main(void)
{
    fixed a;
    fixed b(a);
    fixed c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return (0);
}
