#ifndef CLASSIFIER_H
#define CLASSIFIER_H
#include "Flower.h"
#include <vector>
class Classifier
{
public:
    /**
     * Return a label predicted for a Flower.
     */
    virtual std::string predict(const Flower &f)=0;
};
#endif