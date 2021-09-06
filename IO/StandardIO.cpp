#include "StandardIO.h"

std::string StandardIO::read()
{
    std::string in;
    std::cin >> in;
    return in;
}

void StandardIO::write(std::string str)
{
    std::cout << str << std::endl;
}