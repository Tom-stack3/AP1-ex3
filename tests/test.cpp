#include "../utils/InputValidator.h"
#include "../utils/StringFunctions.h"
#include "../utils/Reader.h"

#include <fstream>
#include <iostream>

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

void testReader()
{
    std::cout << "Reader test:" << std::endl;

    std::cout << "test 1: reading from a file with no labels" << std::endl;
    Classified::distMetric d = &EucDistance::getDist;
    // Create a new Reader instance
    Reader r = Reader(std::string("../client/data/Unclassified.csv"), &d);
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
}

int main(int argc, char **argv)
{
    testReader();
}