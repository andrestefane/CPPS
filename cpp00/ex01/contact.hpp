/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 19:37:23 by astefane          #+#    #+#             */
/*   Updated: 2025/12/01 12:19:33 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string.h>
# include <iostream>
# include <sstream>
# include <iomanip>

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phone;
	std::string secret;

public:
	Contact();

	void setFirstName(const std::string &str);
	void setLastName(const std::string &str);
	void setNickName(const std::string &str);
	void setPhone(const std::string &str);
	void setSecret(const std::string &str);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhone() const;
	std::string getSecret() const;
};

#endif