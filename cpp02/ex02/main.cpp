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
    fixed b(10);
    fixed c(42.42f);
    fixed d(b);
    fixed sum = b + c;
    fixed sub = c - b;
    fixed mul = b * c;
    fixed div = c / b;
    fixed x = 10;
    fixed y(3.3f);
    fixed z(7.7f);
    const fixed cy(1.1f);
    const fixed cz(2.2f);
    fixed s;
    fixed const t(fixed(5.05f) * fixed(2));
	
    std::cout << "\n===== COMPARISON OPERATORS =====" << std::endl;
    std::cout << "b > c  : " << (b > c) << std::endl;
    std::cout << "b < c  : " << (b < c) << std::endl;
    std::cout << "b >= d : " << (b >= d) << std::endl;
    std::cout << "b <= d : " << (b <= d) << std::endl;
    std::cout << "b == d : " << (b == d) << std::endl;
    std::cout << "b != c : " << (b != c) << std::endl;

    std::cout << "\n===== ARITHMETIC OPERATORS =====" << std::endl;

    std::cout << "b + c = " << sum << std::endl;
    std::cout << "c - b = " << sub << std::endl;
    std::cout << "b * c = " << mul << std::endl;
    std::cout << "c / b = " << div << std::endl;

    std::cout << "\n===== INCREMENT / DECREMENT =====" << std::endl;

    std::cout << "x     = " << x << std::endl;
    std::cout << "++x   = " << ++x << std::endl;
    std::cout << "x     = " << x << std::endl;
    std::cout << "x++   = " << x++ << std::endl;
    std::cout << "x     = " << x << std::endl;

    std::cout << "--x   = " << --x << std::endl;
    std::cout << "x     = " << x << std::endl;
    std::cout << "x--   = " << x-- << std::endl;
    std::cout << "x     = " << x << std::endl;

    std::cout << "\n===== MIN / MAX =====" << std::endl;

    std::cout << "min(y, z) = " << fixed::min(y, z) << std::endl;
    std::cout << "max(y, z) = " << fixed::max(y, z) << std::endl;


    std::cout << "min(const) = " << fixed::min(cy, cz) << std::endl;
    std::cout << "max(const) = " << fixed::max(cy, cz) << std::endl;

    std::cout << "\n===== SUBJECT TEST =====" << std::endl;

    std::cout << s << std::endl;
    std::cout << ++s << std::endl;
    std::cout << s << std::endl;
    std::cout << s++ << std::endl;
    std::cout << s << std::endl;
    std::cout << t << std::endl;
    std::cout << fixed::max(s, t) << std::endl;

    return (0);
}