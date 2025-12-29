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
    fixed const b(55);
    fixed const c(42.42f);
    fixed const d(b);
	
    
    a = fixed(12);
    std::cout << "Printing Numbers" << std::endl;
    std::cout << "A is = " << a << std::endl;
    std::cout << "B is = " << b << std::endl;
    std::cout << "C is = " << c << std::endl;
    std::cout << "D is = " << d << std::endl;

    std::cout << "Print float in to FLOAT" << std::endl;
    std::cout << "a is " << a.toFloat() << " as integer" << std::endl;
    std::cout << "b is " << b.toFloat() << " as integer" << std::endl;
    std::cout << "c is " << c.toFloat() << " as integer" << std::endl;
    std::cout << "d is " << d.toFloat() << " as integer" << std::endl;

    std::cout << "Print float in to INT" << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    std::cout << "RawBits" << std::endl;
    std::cout << "a rawBits = " << a.getRawBits() << std::endl;
    std::cout << "b rawBits = " << b.getRawBits() << std::endl;
    std::cout << "c rawBits = " << c.getRawBits() << std::endl;
    std::cout << "d rawBits = " << d.getRawBits() << std::endl;
    return (0);
}
