#include "UploadCommand.h"

void UploadCommand::execute()
{
    getDIO()->write("Please upload your local train CSV file.");
    std::string train = getDIO()->read();

    getDIO()->write("Please upload your local test CSV file.");
    std::string test = getDIO()->read();

    if (!getDIO()->getIOKind().compare(STANDARD_KIND))
    {
        // know that the input is a path
        DataManager *m =  getDataManager();
        Reader trainReader(train, m->getDistMetric());
        Reader testReader(test, m->getDistMetric());

        // doing this to avoid compilation problems.
        std::vector<std::shared_ptr<Classified>> trainVector = (m->getTrainData());
        std::vector<std::shared_ptr<Classified>> testVector = (m->getTestData());

        trainReader.read(trainVector);
        testReader.read(testVector);
    }

    if (!getDIO()->getIOKind().compare(SOCKET_KIND))
    {
        // know that the input is a string contains the contents of a file
    }
}