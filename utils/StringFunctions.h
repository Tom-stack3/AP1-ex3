#ifndef STRING_FUNCTIONS_H
#define STRING_FUNCTIONS_H

#include <string>
#include <vector>
#include <fstream>

class StringFunctions
{
public:
    /**
     * Split the string recieved by the delimiter.
     */
    static std::vector<std::string> split(std::string const &strToSplit, std::string const &delimiter = " ");

    /**
     * Replace a char by a char and return the new string.
     */
    static std::string replaceChar(const std::string &str, char oldChar, char newChar);

    /**
     * Remove a char from a string and return the new string.
     */
    static std::string removeChar(const std::string &str, char oldChar);

    /**
     * Convert csv to string.
     */
    static std::string csvToString(const std::string);
};

#endif