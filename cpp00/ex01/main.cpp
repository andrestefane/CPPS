/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:35:11 by astefane          #+#    #+#             */
/*   Updated: 2025/11/30 21:26:15 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonelist.hpp"

bool isEmpty(const std::string &s)
{
    return (s.empty());
}

bool soloDigitos(const std::string &s)
{
    if (s.empty())
        return false;

    for (size_t i = 0; i < s.length(); i++)
    {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

int main()
{
    PhoneList phone;
    std::string command;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT) ";
        std::getline(std::cin, command);

        if (command == "EXIT")
            break;

        else if (command == "ADD")
        {
            Contact c;
            std::string input;

            std::cout << "First Name: ";
            std::getline(std::cin, input);
            if (isEmpty(input)) continue;
            c.setFirstName(input);

            std::cout << "Last Name: ";
            std::getline(std::cin, input);
            if (isEmpty(input)) continue;
            c.setLastName(input);

            std::cout << "Nickname: ";
            std::getline(std::cin, input);
            if (isEmpty(input)) continue;
            c.setNickName(input);

            std::cout << "Enter phone number: ";
            std::getline(std::cin, input);
            if (!soloDigitos(input))
            {
                std::cout << "Only positive numbers." << std::endl;
                continue;
            }
            c.setPhone(input);

            std::cout << "Secret: ";
            std::getline(std::cin, input);
            if (isEmpty(input)) continue;
            c.setSecret(input);

            phone.addContact(c);
        }

        else if (command == "SEARCH")
        {
            phone.displayContacts();
            if (phone.getTotal() == 0)
                continue;

            std::cout << "Enter number to view contact: ";
            std::getline(std::cin, command);

            std::stringstream ss(command);
            int indx;
            ss >> indx;

            if (ss.fail() || indx < 0 || indx >= phone.getTotal())
            {
                std::cout << "Invalid Number" << std::endl;
                continue;
            }

            Contact c = phone.getContact(indx);

            std::cout << "First Name: " << c.getFirstName() << std::endl;
            std::cout << "Last Name: " << c.getLastName() << std::endl;
            std::cout << "Nickname: " << c.getNickName() << std::endl;
            std::cout << "Phone Number: " << c.getPhone() << std::endl;
            std::cout << "Secret: " << c.getSecret() << std::endl;
        }
    }

    return (0);
}
