#ifndef KNNCLASSIFIER_H
#define KNNCLASSIFIER_H
#include "Flower.h"
#include "Classifier.h"
#include "Algorithm.h"
#include <vector>

class KNNClassifier : public Classifier
{
private:
    std::vector<Flower> m_data;
    // the K we want the prediction to work with.
    int m_k;
    /**
     * Find and return the closest K flowers.
     */
    std::vector<Flower> findKNN(const int k, const Flower &f);

public:
    KNNClassifier(std::vector<Flower> data, const int k = 5);

    /**
     * Return a label predicted for a Flower.
     * (Overiding the interface function)
     */
    std::string predict(const Flower &f);

    /**
     * Set a new K.
     */
    void setK(const int k);
};

#endif