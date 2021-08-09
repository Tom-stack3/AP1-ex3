#include "Classified.h"

void Classified::setLabel(std::string newLabel)
{
    m_label = std::move(newLabel);
}

Classified &Classified::operator=(const Classified &classified)
{
    m_properties = classified.getProperties();
    m_label = classified.getLabel();
    return *this;
}

Classified::Classified(std::vector<double> properties, std::string label)
{
    m_label = std::move(label);
    m_properties = properties;
}

Classified::Classified(const Classified &cls)
{
    m_properties = cls.getProperties();
    m_label = cls.getLabel();
};

const std::vector<double> &Classified::getProperties() const { return m_properties; };

const std::string &Classified::getLabel() const { return m_label; };