/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 09:21:11 by astefane          #+#    #+#             */
/*   Updated: 2026/01/03 13:50:57 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
bool    bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);

    Point p1(5, 5);   // in
    Point p2(10, 10); // out
    Point p3(0, 0);   // vertex

    std::cout << std::boolalpha;
    std::cout << "p1 inside: " << bsp(a, b, c, p1) << std::endl;
    std::cout << "p2 inside: " << bsp(a, b, c, p2) << std::endl;
    std::cout << "p3 inside: " << bsp(a, b, c, p3) << std::endl;

    return (0);
}
