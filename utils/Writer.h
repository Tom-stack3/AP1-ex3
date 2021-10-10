#ifndef WRITER_H
#define WRITER_H
#include "../classifier/Classified.h"
#include <vector>
#include <fstream>

class Writer
{
private:
    std::string m_outputPath;

public:
    Writer(std::string outputPath);

    /**
     * Set a new output path.
     */
    void setOutputPath(std::string outputPath);

    /**
     * Write the vector of Classified objects to the output file.
     */
    void write(const std::vector<std::shared_ptr<Classified>> &classifiedObjects) const;

    /**
     * Write a string to the output file.
     */
    void write(const std::string) const;
};

#endif