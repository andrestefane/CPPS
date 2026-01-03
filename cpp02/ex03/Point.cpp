/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:42:43 by astefane          #+#    #+#             */
/*   Updated: 2026/01/03 09:27:24 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point &other) : _x(other._x), _y(other._y)
{   
}

Point &Point::operator=(const Point &other)
{
    (void)other;
	return(*this);
}

Point::~Point()
{
}
fixed Point::getX() const
{
	return (_x);
}

fixed Point::getY() const
{
	return (_y);
}