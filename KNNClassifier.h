#ifndef KNNCLASSIFIER_H
#define KNNCLASSIFIER_H
#include "Flower.h"
#include "Classifier.h"
#include "Algorithm.h"
#include <vector>

class KNNClassifier : public Classifier
{
private:
    std::vector<Flower> data;
    /**
     * Find and return the closest K flowers.
     */
    std::vector<Flower> findKNN(const int k, const Flower &f);

public:
    KNNClassifier(std::vector<Flower> data);

    /**
     * Return a label predicted for a Flower.
     * (Overiding the interface function)
     */
    std::string predict(const Flower &f);
};

#endif