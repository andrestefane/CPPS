/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:20:50 by astefane          #+#    #+#             */
/*   Updated: 2025/11/30 18:48:52 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "*LOUD AND UNBEARABLE FEEDBACK NOISE*" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		std::string arg = argv[i];
		for (size_t j = 0; j < arg.length(); j++)
        	std::cout << static_cast<char>(std::toupper(arg[j]));
		std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
