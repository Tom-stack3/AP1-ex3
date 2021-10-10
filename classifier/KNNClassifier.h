#ifndef KNNCLASSIFIER_H
#define KNNCLASSIFIER_H
#include "Classified.h"
#include "Classifier.h"
#include "Algorithm.h"
#include <vector>

class KNNClassifier : public Classifier
{
private:
    std::vector<std::shared_ptr<Classified>> m_data;
    // the K we want the prediction to work with.
    int m_k;

public:
    KNNClassifier(std::vector<std::shared_ptr<Classified>> &data, const int k = 5);

    /**
     * Return a label predicted for a classified object.
     * (Overiding the interface function)
     */
    std::string predict(const Classified &f);

    /**
     * Set a new K.
     */
    void setK(const int k);
};

#endif