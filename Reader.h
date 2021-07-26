#ifndef READER_H
#define READER_H
#include <vector>
#include <fstream>
#include "Flower.h"

class Reader
{
private:
    std::string m_inputPath;
    /**
     * Parse a line into a Flower.
     */
    Flower parseLine(std::string &line);

public:
    Reader(std::string inputPath);

    /**
     * Set a new input path.
     */
    void setInputPath(std::string inputPath);

    /**
     * Write the vector of Flowers to the output file.
     */
    std::vector<Flower> read();
};

#endif