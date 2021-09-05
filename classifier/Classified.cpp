#include "Classified.h"

void Classified::setLabel(std::string newLabel)
{
    m_label = std::move(newLabel);
}

Classified &Classified::operator=(const Classified &cls)
{
    m_properties = cls.getProperties();
    m_label = cls.getLabel();
    m_dist = cls.getDistMetric();
    return *this;
}

Classified::Classified(std::vector<double> properties, std::string label, std::string distanceType)
{
    m_label = std::move(label);
    m_properties = properties;
    if (distanceType == "EUC")
    {
        m_dist = &EucDistance::getDist;
    }
    else if (distanceType == "MAN")
    {
        m_dist = &ManDistance::getDist;
    }
    else if (distanceType == "CHE")
    {
        m_dist = &CheDistance::getDist;
    }
    else
    {
        perror(std::string("Error! not a valid distance metric: " + distanceType).c_str());
        exit(1);
    }
}

Classified::Classified(const Classified &cls)
{
    m_properties = cls.getProperties();
    m_label = cls.getLabel();
    m_dist = cls.getDistMetric();
};

const std::vector<double> &Classified::getProperties() const { return m_properties; };

const std::string &Classified::getLabel() const { return m_label; };

Classified::distMetric Classified::getDistMetric() const { return m_dist; }

double Classified::getDistance(const Classified &cls) const
{
    return m_dist(*this, cls);
}