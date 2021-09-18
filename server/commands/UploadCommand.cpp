#include "UploadCommand.h"

void UploadCommand::execute()
{
    DataManager *m = getDataManager();
    std::vector<std::shared_ptr<Classified>> trainVector;
    std::vector<std::shared_ptr<Classified>> testVector;

    getDIO()->write("Please upload your local train CSV file.");
    std::string train = getDIO()->read();

    if (!getDIO()->getIOKind().compare(StandardIO::KIND))
    {
        // The input is a path
        Reader trainReader = Reader(train, m->getDistMetric());
        trainReader.read(trainVector);
    }
    else if (!getDIO()->getIOKind().compare(SocketIO::KIND))
    {
        // The input is a string contains the contents of a file
        Reader trainReader = Reader(m->getDistMetric());
        trainReader.read(trainVector, train);
    }

    getDIO()->write("Upload complete.\nPlease upload your local test CSV file.");

    std::string test = getDIO()->read();

    if (!getDIO()->getIOKind().compare(StandardIO::KIND))
    {
        // The input is a path
        Reader testReader = Reader(test, m->getDistMetric());
        testReader.read(testVector);
    }
    else if (!getDIO()->getIOKind().compare(SocketIO::KIND))
    {
        // The input is a string contains the contents of a file
        Reader testReader = Reader(m->getDistMetric());
        testReader.read(testVector, test);
    }

    getDIO()->write("Upload complete.\n");

    m->setTestData(testVector);
    m->setTrainData(trainVector);
}