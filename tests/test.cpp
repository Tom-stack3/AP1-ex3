#include "test.h"

void testIsDouble()
{
    std::cout << "isDouble():" << std::endl;
    std::cout << InputValidator::isDouble("67.99") << std::endl;
    std::cout << InputValidator::isDouble("67.0") << std::endl;
    std::cout << InputValidator::isDouble("0") << std::endl;
    std::cout << InputValidator::isDouble("69") << std::endl;
    std::cout << InputValidator::isDouble("-9") << std::endl;
    std::cout << InputValidator::isDouble("9g") << std::endl;
}

void testIsInt()
{
    std::cout << "isInt():" << std::endl;
    std::cout << InputValidator::isInt("67.99") << std::endl;
    std::cout << InputValidator::isInt("67.0") << std::endl;
    std::cout << InputValidator::isInt("0") << std::endl;
    std::cout << InputValidator::isInt("69") << std::endl;
    std::cout << InputValidator::isInt("-9") << std::endl;
    std::cout << InputValidator::isInt("9g") << std::endl;
}

void testSplit()
{
    std::cout << "split():" << std::endl;

    std::vector<std::string> strSplitted = StringFunctions::split("4.6,3.1,1.5,0.2", ",");
    for (auto f : strSplitted)
    {
        std::cout << "'" << f << "'" << std::endl;
    }

    strSplitted = StringFunctions::split("test of , this,func,, ", " ");
    for (auto f : strSplitted)
    {
        std::cout << "'" << f << "'" << std::endl;
    }
}

void testCommands()
{
    DataManager d = DataManager();
    StandardIO std = StandardIO();
    DefaultIO *dio = &std;

    Classified::distMetric euc = &EucDistance::getDist;
    // Create a new Reader instance
    // Reader r = Reader(std::string("../../server/data/Iris_train.csv"), &euc);
    // // Load the train data
    // std::vector<std::shared_ptr<Classified>> train;
    // r.read(train);
    // // Load the test data
    // r.setInputPath("../../server/data/Iris_test.csv");
    // std::vector<std::shared_ptr<Classified>> test;
    // r.read(test);

    // d.setTrainData(train);
    // d.setTestData(test);

    DisplayCommand disp = DisplayCommand(dio, &d);
    ClassifyCommand classify = ClassifyCommand(dio, &d);
    ConfusionMatrixCommand confusionMatrix = ConfusionMatrixCommand(dio, &d);
    SettingsCommand settings = SettingsCommand(dio, &d);
    UploadCommand upload = UploadCommand(dio, &d);

    upload.execute();
    classify.execute();
    confusionMatrix.execute();
    settings.execute();
    classify.execute();
    confusionMatrix.execute();
    disp.execute();
    dio->write(confusionMatrix.getDescription() + ", " + classify.getDescription());
}

void testCLI()
{
    DataManager d = DataManager();
    StandardIO std = StandardIO();
    DefaultIO *dio = &std;

    CLI c = CLI(dio, &d);
    c.start();
}

void testReader()
{
    std::cout << "Reader test:" << std::endl;

    std::cout << "test 1: reading from a file with no labels" << std::endl;
    Classified::distMetric d = &EucDistance::getDist;
    // Create a new Reader instance
    Reader r = Reader(std::string("../../client/data/Unclassified.csv"), &d);
    // Read and load the Classified Flowers
    std::vector<std::shared_ptr<Classified>> classifiedObjects;
    r.read(classifiedObjects);

    for (auto f : classifiedObjects)
    {
        std::cout << "num of properties:" << f->getProperties().size() << ", first property:" << f->getProperties()[0] << ", label:" << f->getLabel() << std::endl;
    }

    std::cout << std::endl
              << "test 2: reading from a string and not from a file:" << std::endl
              << std::endl;

    std::vector<std::shared_ptr<Classified>> classifiedObjects2;
    r.read(classifiedObjects2, "4.2,5,marco\n8,4,polo");

    for (auto f : classifiedObjects2)
    {
        std::cout << "num of properties:" << f->getProperties().size() << ", first property:" << f->getProperties()[0] << ", label:" << f->getLabel() << std::endl;
    }

    std::cout << std::endl
              << "test 3: changing the reader path and reading from a file with labels:" << std::endl
              << std::endl;

    r.setInputPath("../../server/data/classified.csv");
    std::vector<std::shared_ptr<Classified>> classifiedObjects3;
    r.read(classifiedObjects3);

    for (auto f : classifiedObjects3)
    {
        std::cout << "num of properties:" << f->getProperties().size() << ", first property:" << f->getProperties()[0] << ", label:" << f->getLabel() << std::endl;
    }
}

void testDistances()
{
    std::vector<double> f1{1.2, 4.5, 9.1, 10};
    std::vector<double> f2{14.1, 8, 0.5, 1.2};
    std::vector<double> f3{4, 2, 3, 9.8};
    Classified c1(f1, nullptr);
    Classified c2(f2, nullptr);
    Classified c3(f3, nullptr);

    std::cout << "EucDistance " << EucDistance::getDist(c1, c2) << std::endl; // should be 18.1676
    std::cout << "CheDistance " << CheDistance::getDist(c1, c2) << std::endl; // should be 12.9
    std::cout << "ManDistance " << ManDistance::getDist(c1, c2) << std::endl; // should be 33.8
    std::cout << std::endl;

    std::cout << "EucDistance " << EucDistance::getDist(c2, c1) << std::endl; // should be 18.1676
    std::cout << "CheDistance " << CheDistance::getDist(c2, c1) << std::endl; // should be 12.9
    std::cout << "ManDistance " << ManDistance::getDist(c2, c1) << std::endl; // should be 33.8
    std::cout << std::endl;

    std::cout << "EucDistance " << EucDistance::getDist(c3, c2) << std::endl; // should be 14.7723
    std::cout << "CheDistance " << CheDistance::getDist(c3, c2) << std::endl; // should be 10.1
    std::cout << "ManDistance " << ManDistance::getDist(c3, c2) << std::endl; // should be 27.2
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    testDistances();
}