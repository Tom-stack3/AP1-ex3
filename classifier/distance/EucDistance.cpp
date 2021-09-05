#include "EucDistance.h"

double EucDistance::getDist(const Classified &cls1, const Classified &cls2)
{
    std::vector<double> properites1 = cls1.getProperties();
    std::vector<double> properites2 = cls2.getProperties();
    double euclideanDist = 0;
    for (int i = 0; i < properites1.size(); i++)
    {
        euclideanDist += pow(properites2[i] - properites1[i], 2);
    }

    return sqrt(euclideanDist);
}