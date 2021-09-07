#ifndef SPLIT_H
#define SPLIT_H

#include <string>
#include <vector>

class Split
{
public:
    /**
     * Split the string recieved by the delimiter.
     */
    static std::vector<std::string> split(std::string const &strToSplit, std::string const &delimiter = " ");
};

#endif