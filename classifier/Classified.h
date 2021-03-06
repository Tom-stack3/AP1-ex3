#ifndef CLASSIFIED_H
#define CLASSIFIED_H
#include "distance/EucDistance.h"
#include "distance/ManDistance.h"
#include "distance/CheDistance.h"

#include <string>
#include <vector>
#include <memory>

class Classified
{
public:
    typedef double (*distMetric)(const Classified &, const Classified &);

private:
    // the properties of the classified object.
    std::vector<double> m_properties;
    // the label of the classified object.
    std::string m_label;
    // the distance metric
    distMetric *m_dist;

public:
    // constructors
    Classified(const Classified &f);
    Classified(std::vector<double> properties, distMetric *distMetric, std::string label = "");

    Classified &operator=(const Classified &classified);

    /**
     * Return a const reference to the properties of the classified object.
     */
    const std::vector<double> &getProperties() const;

    /**
     * Return a const reference to the label of the classified object.
     */
    const std::string &getLabel() const;

    /**
     * Return a ptr to the distance metric used.
     */
    distMetric *getDistMetric() const;

    /**
     * Set a new distance metric.
     */
    void setDistMetric(distMetric *);

    /**
     * Set a new label.
     */
    void setLabel(std::string newLabel);

    /**
     * Delete the label.
     */
    void deleteLabel();

    /**
     * Get distance between this classified object and other classified object.
     */
    double getDistance(const Classified &f) const;
};

#endif