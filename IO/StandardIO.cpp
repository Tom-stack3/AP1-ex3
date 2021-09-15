#include "StandardIO.h"

std::string StandardIO::read() const
{
    std::string in;
    std::getline(std::cin, in);
    return in;
}

void StandardIO::write(std::string str) const
{
    std::cout << str << std::endl;
}

std::string StandardIO::getIOKind() const
{
    return STANDARD_KIND;
}