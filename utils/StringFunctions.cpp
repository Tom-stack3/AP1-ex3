#include "StringFunctions.h"

std::vector<std::string> StringFunctions::split(std::string const &strToSplit, std::string const &delimiter)
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

std::string StringFunctions::replaceChar(const std::string &str, char oldChar, char newChar)
{
    std::string newStr = str;
    for (int i = 0; i < str.length(); ++i)
    {
        if (newStr[i] == oldChar)
            newStr[i] = newChar;
    }

    return newStr;
}

std::string StringFunctions::removeChar(const std::string &str, char c)
{
    std::string output;
    output.reserve(str.size()); // avoids buffer reallocations in the loop
    for (size_t i = 0; i < str.size(); ++i)
        if (str[i] != c)
            output += str[i];
    return output;
}

std::string StringFunctions::csvToString(const std::string path)
{
    std::string line;
    std::string sTotal;

    // Open the input file.
    std::ifstream fileRead(path);

    while (getline(fileRead, line))
    {
        // Add a line to the string.
        sTotal += line + '\n';
    }
    fileRead.close();

    // Remove the last '\n
    sTotal = sTotal.substr(0, sTotal.size() - 1);
    return sTotal;
}