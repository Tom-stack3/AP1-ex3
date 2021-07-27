#include <iostream>
#include "KNNClassifier.h"

KNNClassifier::KNNClassifier(std::vector<Flower> flowerArray)
{
    data = flowerArray;
}

std::vector<Flower> KNNClassifier::findKNN(const int k, const Flower &flower)
{
    // Sotring the array
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data.size() - 1; j++)
        {
            if (data[j].getDistance(flower) > data[j + 1].getDistance(flower))
            {
                Flower temp(data[j]);
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    std::vector<Flower> flowers;
    for (int i = 0; i < k; i++)
    {
        flowers.push_back(data[i]);
    }
    return flowers;
}

std::string KNNClassifier::predict(const Flower & flower){
    int k = 4;
     std::vector<Flower> knnFlowers = findKNN(k, flower);
     std::map<std::string, int> result; 
    for(int i = 0; i < k; i++) {
       result[knnFlowers[i].getLabel()]++;
    }
    for(auto item : result){
        std::cout << item.first + " : " << item.second << "\n";
    }
    return "Shalom";
}