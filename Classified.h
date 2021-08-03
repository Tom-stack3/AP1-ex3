#ifndef CLASSIFIED_H
#define CLASSIFIED_H
#include <string>
#include <vector>
#include <math.h>
#include <memory>
class Classified
{
private:
    // the properties of the classified object.
    std::vector<double> m_properties;
    // the label of the classified object.
    std::string m_label;

public:
    // constructors
    Classified(const Classified &f);
    Classified(std::vector<double> properties, std::string label = "");

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
     * Set a new label.
     */
    void setLabel(std::string newLabel);

    /**
     * Get distance between this classified object and other classified object.
     */
    virtual double getDistance(const Classified &f) const=0;

    //virtual std::shared_ptr<Classified> clone() const = 0;
};

#endif