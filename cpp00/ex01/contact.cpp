/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 21:08:44 by astefane          #+#    #+#             */
/*   Updated: 2025/11/30 21:14:31 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() {}

void Contact::setFirstName(const std::string &str) { firstName = str; }
void Contact::setLastName(const std::string &str) { lastName = str; }
void Contact::setNickName(const std::string &str) { nickname = str; }
void Contact::setPhone(const std::string &str) { phone = str; }
void Contact::setSecret(const std::string &str) { secret = str; }

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickName() const { return nickname; }
std::string Contact::getPhone() const { return phone; }
std::string Contact::getSecret() const { return secret; }
