#ifndef CLASSIFIED_H
#define CLASSIFIED_H
#include "distance/EucDistance.h"
#include <string>
#include <vector>

#include <memory>
class Classified
{
private:
    // the properties of the classified object.
    std::vector<double> m_properties;
    // the label of the classified object.
    std::string m_label;
    // the distance metric
    double (*m_dist)(const Classified&, const Classified&);

public:
    // constructors
    Classified(const Classified &f);
    Classified(std::vector<double> properties, std::string label = "", std::string distanceType = "EUC");

    Classified &operator=(const Classified &classified);

    /**
     * Return a const reference to the properties of the classified object.
     */
    const std::vector<double> &getProperties() const;

    /**
     * Return a const reference to the label of the classified object.
     */
    const std::string &getLabel() const;

    typedef double (*distMetric)(const Classified&, const Classified&);

    /**
     * Return a ptr to the distance metric used.
     */
    distMetric getDistMetric() const;

    /**
     * Set a new label.
     */
    void setLabel(std::string newLabel);

    /**
     * Get distance between this classified object and other classified object.
     */
    double getDistance(const Classified &f) const;
};

#endif