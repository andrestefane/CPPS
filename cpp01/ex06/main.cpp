#include "harl.hpp"

int getLevelIndex(std::string level)
{
    std::string levels[4] =
    {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
            return (i);
    }
    return (-1);
}

int main(int argc, char **argv)
{
    harl h;

    if (argc != 2)
    {
        std::cout << "Usage: ./harlFilter <LEVEL>" << std::endl;
        return (1);
    }
    switch (getLevelIndex(argv[1]))
    {
        case 0:
            h.complain("DEBUG");
            /* fall through */
        case 1:
            h.complain("INFO");
            /* fall through */
        case 2:
            h.complain("WARNING");
            /* fall through */
        case 3:
            h.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    return (0);
}
