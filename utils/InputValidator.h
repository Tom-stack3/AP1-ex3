#ifndef INPUT_VALIDATOR_H
#define INPUT_VALIDATOR_H

#include <sstream>
#include <algorithm>

class InputValidator
{
public:
    /**
     * Returns true if the str is a valid double, Otherwise - returns false.
     */
    static bool isDouble(std::string const &str);
    
    /**
     * Returns true if the str is a valid integer, Otherwise - returns false.
     */
    static bool isInt(std::string const &str);
};

#endif