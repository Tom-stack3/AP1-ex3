#ifndef CLASSIFIER_H
#define CLASSIFIER_H
#include "Classified.h"
#include <vector>

class Classifier
{
public:
    /**
     * Return a label predicted for a Classified object.
     */
    virtual std::string predict(const Classified &f) = 0;

    /**
     * Classify the vector.
     */
    virtual void predict(std::vector<std::shared_ptr<Classified>>);
};
#endif