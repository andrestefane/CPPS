/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestFormmain.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:14:04 by astefane          #+#    #+#             */
/*   Updated: 2026/02/02 20:42:31 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestFormmain.hpp"

RobotomyRequestFormmain::RobotomyRequestFormmain()
	: AForm("RobotomyRequestFormmain", 72, 42), _target("default")
{
	
}

RobotomyRequestFormmain::RobotomyRequestFormmain(const std::string& target)
	: AForm("RobotomyRequestFormmain", 72, 45), _target(target)
{

}

RobotomyRequestFormmain::RobotomyRequestFormmain(const RobotomyRequestFormmain& other)
	: AForm(other), _target(other._target)
{

}

RobotomyRequestFormmain& RobotomyRequestFormmain::operator=(const RobotomyRequestFormmain& other)
{
	if (this != &other)
		_target = other._target;
	return (*this);
}

RobotomyRequestFormmain::~RobotomyRequestFormmain()
{

}

void	RobotomyRequestFormmain::executionAction() const
{
	std::cout << " drilling noises *" << std::endl;

	if (std::rand() % 2)
}