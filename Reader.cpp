#include "Reader.h"

Reader::Reader(std::string inputPath)
{
    m_inputPath = std::move(inputPath);
}

void Reader::setInputPath(std::string inputPath)
{
    m_inputPath = std::move(inputPath);
}

std::unique_ptr<Classified> Reader::parseLine(std::string &line) const
{
    const std::string comma = ",";
    std::vector<std::string> strSplitted;

    //split the string by a comma and save the parts in the vector strSplitted.
    int start = 0;
    int end = line.find(comma);
    while (end != -1)
    {
        strSplitted.push_back(line.substr(start, end - start));
        start = end + comma.size();
        end = line.find(comma, start);
    }
    strSplitted.push_back(line.substr(start, end - start));

    // if the row doesn't have a label, we add an empty one.
    if (strSplitted.size() == 4)
    {
        strSplitted.push_back(std::string(""));
    }
    std::vector<double> properties;
    for (int i = 0; i < 4; i++)
    {
        // string to double
        properties.push_back(std::stod(strSplitted.at(i)));
    }
    return std::make_unique<Flower>(properties, strSplitted.at(4));
}

void Reader::read(std::vector<std::unique_ptr<Classified>>& v) const
{
    std::string line;
    // open the input file.
    std::ifstream fileRead(m_inputPath);

    while (getline(fileRead, line))
    {
        // add a flower to the vector.
        v.push_back(parseLine(line));
    }
    fileRead.close();
}