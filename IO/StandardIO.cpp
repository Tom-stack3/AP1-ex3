#include "StandardIO.h"

std::string StandardIO::read() const
{
    std::string in;
    std::getline(std::cin, in);
    return in;
}

void StandardIO::write(std::string str) const
{
    std::cout << str;
}

std::string StandardIO::getIOKind() const
{
    return StandardIO::KIND;
}