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
    std::vector<std::shared_ptr<Classified>> knnFlowers = algo.getKSmallest(m_data, m_k);
    // return the string that apperes max times in the array

    // stores the amount each lable apperes in the array.

    // creates a map with the key as the lables, and the value as the number of apperences in the array.
    std::map<std::string, int> map;
    for (std::shared_ptr<Classified> &classified : knnFlowers)
    {
        map[classified->getLabel()]++;
    }

    // get the string that apperes max times in the map
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