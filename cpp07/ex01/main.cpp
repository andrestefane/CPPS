#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>

void print(T const &elem)
{
	std::cout << elem << std::endl;
}

template <typename T>

void increment(T &elem)
{
	elem++;
}

void toUpper(char &c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 'a' + 'A';
}

int main( void )
{
    std::cout << "=== int array (print) ===" << std::endl;
    int intArr[] = {1, 2, 3, 4, 5};
    ::iter(intArr, 5, print<int>);

    std::cout << "\n=== int array (increment + print) ===" << std::endl;
    ::iter(intArr, 5, increment<int>);
    ::iter(intArr, 5, print<int>);

    std::cout << "\n=== double array (print) ===" << std::endl;
    double dblArr[] = {1.1, 2.2, 3.3};
    ::iter(dblArr, 3, print<double>);

    std::cout << "\n=== string array (print) ===" << std::endl;
    std::string strArr[] = {"hello", "world", "42"};
    ::iter(strArr, 3, print<std::string>);

    std::cout << "\n=== char array (toUpper) ===" << std::endl;
    char charArr[] = {'a', 'b', 'c', 'd', 'e'};
    ::iter(charArr, 5, toUpper);
    ::iter(charArr, 5, print<char>);

    std::cout << "\n=== const int array (print) ===" << std::endl;
    int const constArr[] = {10, 20, 30};
    ::iter(constArr, 3, print<int>);

    return 0;
}