#include "Reader.h"

Reader::Reader(std::string inputPath, Classified::distMetric *distMetric)
{
    m_inputPath = std::move(inputPath);
    m_distMetric = distMetric;
}

Reader::Reader(Classified::distMetric *distMetric)
{
    m_inputPath = nullptr;
    m_distMetric = distMetric;
}

void Reader::setInputPath(std::string inputPath)
{
    m_inputPath = std::move(inputPath);
}

std::shared_ptr<Classified> Reader::parseLine(std::string &line) const
{
    // Remove the '\r' char
    line = StringFunctions::removeChar(line, '\r');

    const std::string comma = ",";
    std::vector<std::string> strSplitted = StringFunctions::split(line, comma);

    // If the row doesn't have a label, we add an empty one.
    if (strSplitted.size() == m_numOfProperties)
    {
        strSplitted.push_back(std::string(""));
    }
    std::vector<double> properties;
    for (int i = 0; i < m_numOfProperties; i++)
    {
        // String to double
        properties.push_back(std::stod(strSplitted.at(i)));
    }
    return std::make_shared<Classified>(properties, m_distMetric, strSplitted.at(m_numOfProperties));
}

void Reader::initNumOfProperties(std::string firstLine)
{
    // Remove the '\r' char
    firstLine = StringFunctions::removeChar(firstLine, '\r');

    const std::string comma = ",";
    std::vector<std::string> strSplitted = StringFunctions::split(firstLine, comma);

    int len = strSplitted.size();
    int numOfProperties = 0;
    for (auto const &p : strSplitted)
    {
        if (InputValidator::isDouble(p))
        {
            numOfProperties++;
        }
        else
        {
            break;
        }
    }
    m_numOfProperties = numOfProperties;
}

void Reader::read(std::vector<std::shared_ptr<Classified>> &v)
{
    std::string line;
    // Open the input file.
    std::ifstream fileRead(m_inputPath);

    if (fileRead.fail())
    {
        throw std::runtime_error("Error! failed to read the file: " + m_inputPath);
    }

    // Read the first line
    getline(fileRead, line);
    // init the num of properties the classified objects have based on the first line of the file
    initNumOfProperties(line);
    // Add a classified to the vector.
    v.push_back(parseLine(line));

    while (getline(fileRead, line))
    {
        // Add a classified to the vector.
        v.push_back(parseLine(line));
    }
    fileRead.close();
}

void Reader::read(std::vector<std::shared_ptr<Classified>> &v, std::string input)
{
    std::string line;
    std::istringstream f(input);

    // Read the first line
    getline(f, line);
    // init the num of properties the classified objects have based on the first line of the file
    initNumOfProperties(line);
    // Add a classified to the vector.
    v.push_back(parseLine(line));

    while (getline(f, line))
    {
        // Add a classified to the vector.
        v.push_back(parseLine(line));
    }
}

std::string Reader::toString()
{
    std::string line;
    std::string sTotal;

    // Open the input file.
    std::ifstream fileRead(m_inputPath);

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