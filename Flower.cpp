#include "Flower.h"

double Flower::getDistance(const Classified &cls) const
{
    std::vector<double> properites = cls.getProperties();
    std::vector<double> this_properites = this->getProperties();
    double euclideanDist = 0;
    for (int i = 0; i < this_properites.size(); i++)
    {
        euclideanDist += pow(this_properites[i] - properites[i], 2);
    }

    return sqrt(euclideanDist);
}

/*
std::shared_ptr<Classified> Flower::clone() const
{
    return std::make_shared<Flower>(*this);
}
*/
