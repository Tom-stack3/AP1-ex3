#include "ClassifyCommand.h"

void ClassifyCommand::execute()
{
    DataManager *d = getDataManager();
    std::vector<std::shared_ptr<Classified>> trained = d->getTrainData();
    std::vector<std::shared_ptr<Classified>> toClassify = d->getClassifiedData();

    // If one of the train vector is empty
    if (trained.empty())
    {
        getDIO()->write("please upload train data, press ENTER to return to main menu\n");
        getDIO()->read();
        return;
    }

    // Create a new KNNClassifier
    KNNClassifier knn(trained, d->getK());
    Classifier &classifier = knn;

    // If the toClassify vector is empty - meaning we didn't classify the objects yet.
    if (toClassify.empty())
    {
        // We create a new vector, from the test data, with empty labels.
        std::vector<std::shared_ptr<Classified>> test = d->getTestData();
        for (auto const & cls : test)
        {
            // Create a copy of the Classified object.
            std::shared_ptr<Classified> newCls = std::make_shared<Classified>(*cls);
            // Delete the previous label
            (*newCls).deleteLabel();
            // Push to the toClassify vector
            toClassify.push_back(newCls);
        }
        // Set the newly created toClassify vector to be the toClassify vector in the Data Manager.
        d->setClassifiedData(toClassify);
    }

    classifier.predict(toClassify);

    getDIO()->write("classifying data complete\n");
}
