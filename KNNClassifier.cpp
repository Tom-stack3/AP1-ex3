#include "KNNClassifier.h"

KNNClassifier::KNNClassifier(std::vector<Flower> flowerArray, int k)
{
    m_data = flowerArray;
    m_k = k;
}

void KNNClassifier::setK(const int k){
    m_k = k;
}

std::vector<Flower> KNNClassifier::findKNN(const int k, const Flower &flower)
{
  // Sotring the array
    for (int i = 0; i < m_data.size(); i++)
    {
        for (int j = 0; j < m_data.size() - 1; j++)
        {
            if (m_data[j].getDistance(flower) > m_data[j + 1].getDistance(flower))
            {
                Flower temp(m_data[j]);
                m_data[j] = m_data[j + 1];
                m_data[j + 1] = temp;
            }
        }
    }

    std::vector<Flower> flowers;
    for (int i = 0; i < k; i++)
    {
        flowers.push_back(m_data[i]);
    }
    return flowers;
}

std::string KNNClassifier::predict(const Flower &flower)
{
    Algorithm<Flower> algo{};
    std::vector<Flower> knnFlowers = algo.getKSmallest(algo.sortByDiffrence(m_data, flower), m_k);
    //std::vector<Flower> knnFlowers = findKNN(k, flower);
    int result[]{0, 0, 0};
    for (int i = 0; i < m_k; i++)
    {
        if (knnFlowers[i].getLabel().compare("Iris-setosa") == 0)
        {
            result[0]++;
        }
        else if (knnFlowers[i].getLabel().compare("Iris-virginica") == 0)
        {
            result[1]++;
        }
        else if (knnFlowers[i].getLabel().compare("Iris-versicolor") == 0)
        {
            result[2]++;
        }
    }

    int max = result[0] > (result[1] > result[2] ? result[1] : result[2]) ? result[0] : (result[1] > result[2] ? result[1] : result[2]);

    if (result[0] == max)
        return "Iris-setosa";
    if (result[1] == max)
        return "Iris-virginica";
    return "Iris-versicolor";
}