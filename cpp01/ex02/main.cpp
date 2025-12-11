/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:19:19 by astefane          #+#    #+#             */
/*   Updated: 2025/12/11 20:21:28 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Memory address of str:      " << &str << std::endl;
    std::cout << "Memory address in stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address in stringREF: " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "Value of str:      " << str << std::endl;
    std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed by stringREF: " << stringREF << std::endl;

    return (0);
}
