#include "Split.h"

std::vector<std::string> Split::split(std::string const &strToSplit, std::string const &delimiter)
{
    std::vector<std::string> strSplitted;

    // Split the string by a comma and save the parts in the vector strSplitted.
    int start = 0;
    int end = strToSplit.find(delimiter);
    while (end != -1)
    {
        strSplitted.push_back(strToSplit.substr(start, end - start));
        start = end + delimiter.size();
        end = strToSplit.find(delimiter, start);
    }
    strSplitted.push_back(strToSplit.substr(start, end - start));
    return strSplitted;
}