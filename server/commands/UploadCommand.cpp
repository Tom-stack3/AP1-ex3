#include "UploadCommand.h"

void UploadCommand::execute()
{
    getDIO()->write("Please upload your local train CSV file.ֿ");

    std::string train = getDIO()->read();
    std::cout << train << std::endl;

    getDIO()->write("Please upload your local test CSV file.");
    std::string test = getDIO()->read();
    std::cout << "Test:\n" + test << std::endl;

    DataManager *m = getDataManager();

    if (!getDIO()->getIOKind().compare(StandardIO::KIND))
    {
        // know that the input is a path
        Reader trainReader = Reader(train, m->getDistMetric());
        Reader testReader = Reader(test, m->getDistMetric());

        std::vector<std::shared_ptr<Classified>> trainVector;
        std::vector<std::shared_ptr<Classified>> testVector;

        trainReader.read(trainVector);
        testReader.read(testVector);

        m->setTestData(testVector);
        m->setTrainData(trainVector);
    }
    else if (!getDIO()->getIOKind().compare(SocketIO::KIND))
    {
        // The input is a string contains the contents of a file
        Reader trainReader = Reader(m->getDistMetric());
        Reader testReader = Reader(m->getDistMetric());

        std::vector<std::shared_ptr<Classified>> trainVector;
        std::vector<std::shared_ptr<Classified>> testVector;

        trainReader.read(trainVector, train);
        testReader.read(testVector, test);

        m->setTestData(testVector);
        m->setTrainData(trainVector);
    }
}