#include "Classifier.h"

void Classifier::predict(std::vector<std::shared_ptr<Classified>> unclassified)
{
    for (auto const &f : unclassified)
    {
        // Set the classified object label to the prediction the Model made
        f->setLabel(this->predict(*f));
    }
}