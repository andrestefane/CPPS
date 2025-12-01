/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonelist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 21:10:40 by astefane          #+#    #+#             */
/*   Updated: 2025/12/01 13:19:50 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonelist.hpp"

PhoneList::PhoneList() : index(0), total(0) {}

std::string PhoneList::truncate(const std::string &str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void PhoneList::addContact(const Contact &c)
{
	contacts[index] = c;
	index = (index + 1) % 8;
	if (total < 8)
		total++;
}

void PhoneList::displayContacts() const
{
	std::cout << std::setw(10) << "Index"
			  << "|" << std::setw(10) << "First Name"
			  << "|" << std::setw(10) << "Last Name"
			  << "|" << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < total; i++)
    {
		std::cout << std::setw(10) << i
				  << "|" << std::setw(10) << truncate(contacts[i].getFirstName())
				  << "|" << std::setw(10) << truncate(contacts[i].getLastName())
				  << "|" << std::setw(10) << truncate(contacts[i].getNickName())
				  << std::endl;
	}
}

Contact PhoneList::getContact(int idx) const
{
	if (idx >= 0 && idx < total)
		return (contacts[idx]);
	return( Contact());
}

int PhoneList::getTotal() const
{
	return (total);
}