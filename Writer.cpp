#include "Writer.h"

Writer::Writer(std::string outputPath)
{
    m_outputPath = std::move(outputPath);
}

void Writer::setOutputPath(std::string outputPath)
{
    m_outputPath = std::move(outputPath);
}

void Writer::write(const std::vector<std::shared_ptr<Classified>>& classifiedObjects) const
{
    std::ofstream outFile(m_outputPath);
    for (auto classified = classifiedObjects.begin(); classified != classifiedObjects.end(); ++classified)
    {
        if(classified + 2 <= classifiedObjects.end()){
            outFile << (*classified)->getLabel() << std::endl;
        }else{
            outFile << (*classified)->getLabel();
        }
    }
    outFile.close();
}