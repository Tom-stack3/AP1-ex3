#include "InputValidator.h"

bool InputValidator::isDouble(std::string const &str)
{
    auto result = double();
    auto i = std::istringstream(str);

    i >> result;

    return !i.fail() && i.eof();
}

bool InputValidator::isInt(const std::string &s)
{
    char *ptr;
    long converted = strtol(s.c_str(), &ptr, 10);
    if (*ptr)
    {
        // conversion failed because the input wasn't a number
        return false;
    }
    return true;
}
