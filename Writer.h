#ifndef WRITER_H
#define WRITER_H
#include <vector>
#include <fstream>
#include "Flower.h"

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
    void write(const std::vector<std::unique_ptr<Classified>>& classifiedObjects) const;
};

#endif