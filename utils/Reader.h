#ifndef READER_H
#define READER_H
#include "../classifier/Classified.h"
#include "StringFunctions.h"
#include "InputValidator.h"

#include <vector>
#include <fstream>
#include <memory>

class Reader
{
private:
    int m_numOfProperties;

    std::string m_inputPath;
    Classified::distMetric *m_distMetric;

    /**
     * Initialize the number of properties the classified objects have based on the first line of the file.
     */
    void initNumOfProperties(std::string firstLine);

    /**
     * Parse a line into a Classified object.
     */
    std::shared_ptr<Classified> parseLine(std::string &line) const;

public:
    Reader(std::string inputPath, Classified::distMetric *distMetric);

    /**
     * Set a new input path.
     */
    void setInputPath(std::string inputPath);

    /**
     * Read and initiazlize the classes.
     */
    void read(std::vector<std::shared_ptr<Classified>> &v);

    /**
     * Read and initiazlize the classes from a string.
     */
    void read(std::vector<std::shared_ptr<Classified>> &v, std::string input);


    /**
     * Return a string of the file read.
     */
    std::string toString();
};

#endif