/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonelist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:12:28 by astefane          #+#    #+#             */
/*   Updated: 2025/11/30 21:10:32 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONELIST_HPP
# define PHONELIST_HPP

# include "contact.hpp"

class PhoneList {
private:
	Contact contacts[8];
	int index;
	int total;

	std::string truncate(const std::string &str) const;

public:
	PhoneList();

	void addContact(const Contact &c);
	void displayContacts() const;
	Contact getContact(int idx) const;
	int getTotal() const;
};

#endif
