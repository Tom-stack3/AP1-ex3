#ifndef KNNCLASSIFIER_H
#define KNNCLASSIFIER_H
#include "Flower.h"
#include <vector>
#include <map>
class KNNClassifier
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
     * Return a label predicted for the Flower.
     * (Overiding the interface function)
     */
    std::string predict(const Flower &f);
};

#endif