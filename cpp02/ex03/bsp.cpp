/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:51:39 by astefane          #+#    #+#             */
/*   Updated: 2026/01/03 09:47:58 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

fixed area(const Point &a, const Point &b, const Point &c)
{
    return ((b.getX() - a.getX()) * (c.getY() - a.getY())
            - (c.getX() - a.getX()) * (b.getY() - a.getY()));  
}

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
    fixed areaABC = area(a, b, c);
    fixed areaPAB = area(point, a, b);
    fixed areaPBC = area(point, b, c);
    fixed areaPCA = area(point, c, a);    

    if ((areaABC == 0) ||(areaPAB == 0) || (areaPBC == 0) || (areaPCA == 0))
        return (false);
    
    bool sing1 = (areaPAB > 0) == (areaABC > 0);
    bool sing2 = (areaPBC > 0) == (areaABC > 0);
    bool sing3 = (areaPCA > 0) == (areaABC > 0);
    
    return (sing1 && sing2 && sing3);
}
