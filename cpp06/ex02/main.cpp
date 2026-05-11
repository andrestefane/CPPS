#include <iostream>
#include <cstdlib>
#include <ctime>
#include "functions.hpp"

int main(void)
{
    std::srand(std::time(NULL));

    for (int i = 0; i < 6; i++)
    {
        std::cout << "\n--- Test " << i + 1 << " ---" << std::endl;

        Base* obj = generate();

        std::cout << "identify(ptr): ";
        identify(obj);

        std::cout << "identify(ref): ";
        identify(*obj);

        delete obj;
    }

    return 0;
}