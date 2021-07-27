#ifndef FLOWER_H
#define FLOWER_H
#include <string>
#include <array>
#include <math.h>
class Flower
{
private:
    // the four properties of the flower.
    std::array<double, 4> m_properties;
    // the label of the flower.
    std::string m_label;

public:
    // constructors
    Flower(){};
    Flower(const Flower &f);
    Flower(std::array<double, 4> properties, std::string label = "");

    Flower &operator=(const Flower &flower);

    /**
     * Return a const reference to the properties of the flower.
     */
    const std::array<double, 4> &getProperties() const;

    /**
     * Return a const reference to the label of the flower.
     */
    const std::string &getLabel() const;

    /**
     * Set a new label.
     */
    void setLabel(std::string newLabel);

    //comparing between 2 flowers
    int compare(Flower &f) const;

    /**
     * Get distance between this flower and other flower.
     */
    double getDistance(const Flower &f) const;
};

#endif