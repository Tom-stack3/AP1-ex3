#include "ClassifyCommand.h"

void ClassifyCommand::execute()
{
    DataManager *d = getDataManager();
    std::vector<std::shared_ptr<Classified>> trained = d->getTrainData();
    std::vector<std::shared_ptr<Classified>> toClassify = d->getClassifiedData();

    // If one of the train vector is empty
    if (trained.empty())
    {
        getDIO()->write("please upload train data");
        return;
    }

    // Create a new KNNClassifier
    KNNClassifier knn(trained, d->getK());
    Classifier &classifier = knn;

    classifier.predict(toClassify);

    getDIO()->write("classifying data complete");
}
