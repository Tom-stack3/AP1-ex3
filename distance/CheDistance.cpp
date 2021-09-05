#include "CheDistance.h"

double CheDistance::getDist(const Classified &cls1, const Classified &cls2)
{
    std::vector<double> properites1 = cls1.getProperties();
    std::vector<double> properites2 = cls2.getProperties();
    double max = 0;
    for (int i = 0; i < properites1.size(); i++)
    {
        double current = std::abs(properites2[i] - properites1[i]);
        if (current > max)
        {
            max = current;
        }
    }
    
    return max;
}