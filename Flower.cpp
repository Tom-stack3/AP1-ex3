#include "Flower.h"

void Flower::setLabel(std::string newLabel)
{
    m_label = std::move(newLabel);
}

Flower::Flower(std::array<int, 4> properties, std::string label)
{
    m_label = std::move(label);
    m_properties = properties;
}