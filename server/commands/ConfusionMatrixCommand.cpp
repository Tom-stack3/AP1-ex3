#include "ConfusionMatrixCommand.h"

void ConfusionMatrixCommand::execute()
{
    DataManager *d = getDataManager();
    // The classified data by the algorithm
    std::vector<std::shared_ptr<Classified>> classified = d->getClassifiedData();
    // The test data
    std::vector<std::shared_ptr<Classified>> test = d->getTestData();

    // If the classified vector is empty - meaning we didn't classify the objects yet.
    if (classified.empty())
    {
        getDIO()->write("please classify the data uploaded");
        return;
    }

    std::vector<std::string> labels = d->getTestLabels();
    // The labels guessed by the classifier
    std::vector<std::string> classifiedLabels;
    // The correct labels from the test data
    std::vector<std::string> correctLabels;

    for (auto const &f : classified)
    {
        classifiedLabels.push_back(f->getLabel());
    }
    for (auto const &f : test)
    {
        correctLabels.push_back(f->getLabel());
    }

    std::string out = "The current KNN parameters are: K = " + std::to_string(d->getK());
    +", distance metric = " + d->getDistMetricName();
    getDIO()->write(out);

    // Wait for the user to press "Enter", then continue to the Commands menu
    getDIO()->read();
}