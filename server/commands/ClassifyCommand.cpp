#include "ClassifyCommand.h"

void ClassifyCommand::execute()
{
    DataManager *d = getDataManager();
    std::vector<std::shared_ptr<Classified>> trained = d->getTrainData();
    std::vector<std::shared_ptr<Classified>> toClassify = d->getClassifiedData();

    // Create a new KNNClassifier
    KNNClassifier knn(trained, d->getK());
    Classifier &classifier = knn;

    classifier.predict(toClassify);
}
