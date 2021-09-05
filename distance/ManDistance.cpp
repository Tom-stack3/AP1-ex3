#include "ManDistance.h"

double ManDistance::getDist(const Classified &cls1, const Classified &cls2)
{
    std::vector<double> properites1 = cls1.getProperties();
    std::vector<double> properites2 = cls2.getProperties();
    double dist = 0;
    for (int i = 0; i < properites1.size(); i++)
    {
        dist += std::abs(properites2[i] - properites1[i]);
    }

    return dist;
}