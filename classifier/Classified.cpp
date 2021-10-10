#include "Classified.h"

void Classified::setLabel(std::string newLabel)
{
    m_label = std::move(newLabel);
}

void Classified::deleteLabel()
{
    setLabel("");
}

void Classified::setDistMetric(distMetric *newDistMetric)
{
    m_dist = newDistMetric;
}

Classified &Classified::operator=(const Classified &cls)
{
    m_properties = cls.getProperties();
    m_label = cls.getLabel();
    m_dist = cls.getDistMetric();
    return *this;
}

Classified::Classified(std::vector<double> properties, Classified::distMetric *distMetric, std::string label)
{
    m_label = std::move(label);
    m_properties = properties;
    setDistMetric(distMetric);
}

Classified::Classified(const Classified &cls)
{
    m_properties = cls.getProperties();
    m_label = cls.getLabel();
    m_dist = cls.getDistMetric();
};

const std::vector<double> &Classified::getProperties() const { return m_properties; };

const std::string &Classified::getLabel() const { return m_label; };

Classified::distMetric *Classified::getDistMetric() const { return m_dist; }

double Classified::getDistance(const Classified &cls) const
{
    return (*m_dist)(*this, cls);
}