#ifndef READER_H
#define READER_H
#include "../classifier/Classified.h"
#include <vector>
#include <fstream>
#include <memory>

class Reader
{
private:
    std::string m_inputPath;
    /**
     * Parse a line into a Classified object.
     */
    std::shared_ptr<Classified> parseLine(std::string &line) const;

public:
    Reader(std::string inputPath);

    /**
     * Set a new input path.
     */
    void setInputPath(std::string inputPath);

    /**
     * Read and initiazlize the classes.
     */
    void read(std::vector<std::shared_ptr<Classified>> &v) const;

    /**
     * Return a string of the file read.
     */
    std::string toString();
};

#endif