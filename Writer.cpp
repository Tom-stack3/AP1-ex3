#include "Writer.h"

Writer::Writer(std::string outputPath)
{
    m_outputPath = std::move(outputPath);
}

void Writer::setOutputPath(std::string outputPath)
{
    m_outputPath = std::move(outputPath);
}

void Writer::write(const std::vector<Flower> flowers) const
{
    std::ofstream outFile(m_outputPath);
    for (Flower const &flower : flowers)
    {
        const std::array<double, 4> &prop = flower.getProperties();
        outFile << flower.getLabel() << std::endl;
    }
    outFile.close();
}