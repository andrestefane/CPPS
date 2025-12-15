/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 20:46:43 by astefane          #+#    #+#             */
/*   Updated: 2025/12/15 21:30:27 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void    betterGNL(const std::string &filename, const std::string &s1, const std::string &s2)
{
    std::ifstream input(filename.c_str());
    std::ostringstream buffer;
    std::string content;
    std::string result;
    size_t pos;
    size_t found;
    if (!input)
    {
        std::cerr << "Error: Cannont open filename" << '\n';
        return ;
    }
    buffer << input.rdbuf();
    content = buffer.str();
    input.close();
    pos = 0;
    while (pos < content.size())
    {
        found = content.find(s1, pos);
        if (found == std::string::npos)
        {
            result.append(content, pos, content.size() - pos);
            break;
        }
        result.append(content, pos, found - pos);
        result += s2;
        pos = found + s1.size();
    }
    std::ofstream output((filename + ".replace").c_str());
    if (!output)
    {
        throw (std::runtime_error("Error: Cannont create output file"));
    }
    output << result;
    output.close();
}

int main (int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Error: Insufficent arguments" << '\n';
        return (1);
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (s1.empty())
    {
        std::cerr << "Error: filename is empty or not exist" << '\n';
        return (1);
    }
    try 
    {
        betterGNL(filename, s1, s2);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return (1);   
    }
    return (0);
}
