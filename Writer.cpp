#include "Writer.h"

Writer::Writer(std::string outputPath)
{
    m_outputPath = std::move(outputPath);
}

void Writer::setOutputPath(std::string outputPath)
{
    m_outputPath = std::move(outputPath);
}

void Writer::write(const std::vector<std::unique_ptr<Classified>>& classifiedObjects) const
{
    std::ofstream outFile(m_outputPath);
    for (const std::unique_ptr<Classified> &classified : classifiedObjects)
    {
        outFile << classified->getLabel() << std::endl;
    }
    outFile.close();
}