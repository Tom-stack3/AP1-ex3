#include "Reader.h"

Reader::Reader(std::string inputPath)
{
    m_inputPath = std::move(inputPath);
}

void Reader::setInputPath(std::string inputPath)
{
    m_inputPath = std::move(inputPath);
}

std::shared_ptr<Classified> Reader::parseLine(std::string &line) const
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
    return std::make_shared<Flower>(properties, strSplitted.at(4));
}

void Reader::read(std::vector<std::shared_ptr<Classified>> &v) const
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

std::string Reader::toString()
{
    std::string s;
    std::string sTotal;

    std::ifstream in;
    in.open(m_inputPath);

    while (!in.eof())
    {
        getline(in, s);
        sTotal += s + "\n";
    }
    return sTotal;
}