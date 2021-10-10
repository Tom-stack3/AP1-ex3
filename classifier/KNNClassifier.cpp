#include "KNNClassifier.h"

KNNClassifier::KNNClassifier(std::vector<std::shared_ptr<Classified>> &classifiedObjects, int k)
{
    m_data = classifiedObjects;
    m_k = k;
}

void KNNClassifier::setK(const int k)
{
    m_k = k;
}

std::string KNNClassifier::predict(const Classified &cls)
{
    Algorithm<Classified> algo;

    algo.sortByDiffrence(m_data, cls);
    std::vector<std::shared_ptr<Classified>> knnObjects = algo.getKSmallest(m_data, m_k);

    // Creates a map with the key as the lables, and the value as the number of apperences in the array
    std::map<std::string, int> map;
    for (auto &classified : knnObjects)
    {
        map[classified->getLabel()]++;
    }

    // Get the string that apperes the most in the map
    std::string maxString;
    int max = 0;

    for (auto const &x : map)
    {
        if (x.second > max)
        {
            max = x.second;
            maxString = x.first;
        }
    }
    return maxString;
}