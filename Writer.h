#ifndef WRITER_H
#define WRITER_H
#include <string>
#include <vector>
#include <fstream>
#include "Flower.h"

class Writer{
private:
    std::string m_outputPath;
public:
    Writer(std::string outputPath);

    /**
     * Set a new output path.
     */
    void setOutputPath(std::string outputPath);

    void write(std::vector<Flower> flowers);
};

#endif