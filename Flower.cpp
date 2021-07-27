#include "Flower.h"

void Flower::setLabel(std::string newLabel)
{
    m_label = std::move(newLabel);
}

Flower &Flower::operator=(const Flower &flower)
{
    m_properties = flower.getProperties();
    m_label = flower.getLabel();
    return *this;
}

Flower::Flower(std::array<double, 4> properties, std::string label)
{
    m_label = std::move(label);
    m_properties = properties;
}

double Flower::getDistance(const Flower &f) const
{
    double x11 = m_properties[0];
    double x12 = m_properties[1];
    double y11 = m_properties[2];
    double y12 = m_properties[3];

    double x21 = f.m_properties[0];
    double x22 = f.m_properties[1];
    double y21 = f.m_properties[2];
    double y22 = f.m_properties[3];

    return sqrt(pow(x11 - x21, 2) + pow(x12 - x22, 2) + pow(y11 - y21, 2) + pow(y12 - y22, 2));
}