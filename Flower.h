#ifndef FLOWER_H
#define FLOWER_H
#include "Classified.h"
#include <string>
#include <array>
#include <math.h>
class Flower : public Classified
{
public:
    // constructors
    Flower(const Classified &f) : Classified(f) {};
    Flower(std::vector<double> properties, std::string label = "") : Classified(properties, label) {};

    /**
     * Get euclidean distance between this classified object and other classified object.
     */
    double getDistance(const Classified &cls) const;

    std::unique_ptr<Classified> clone() const;
};

#endif