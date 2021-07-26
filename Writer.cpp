#include "Writer.h"
#include <iostream>

Writer::Writer(std::string outputPath){
    m_outputPath = std::move(outputPath);
}

void Writer::setOutputPath(std::string outputPath) {
    m_outputPath = std::move(outputPath);
}

void Writer::write(const std::vector<Flower> flowers) const{
    std::ofstream outFile(m_outputPath);
    for(Flower const& flower: flowers) {
        const std::array<int,4>& prop = flower.getProperties();
        outFile << prop[0] << ',' << prop[1] << ',' << prop[2] << ',' << prop[3] << ',' << flower.getLabel() << '\n';
    }
    outFile.close();
}