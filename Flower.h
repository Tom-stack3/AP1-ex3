#ifndef FLOWER_H
#define FLOWER_H
#include <string>
#include <array>

class Flower
{
private:
    // the four properties of the flower.
    std::array<int,4> m_properties;
    // the label of the flower.
    std::string m_label;
public:
    Flower(std::array<int,4> properties, std::string label = "");

    /**
     * Return a const reference to the properties of the flower.
     */
    const std::array<int,4>& getProperties() const { return m_properties; };

    /**
     * Return a const reference to the label of the flower.
     */
    const std::string& getLabel() const { return m_label; };

    /**
     * Set a new label.
     */
    void setLabel(std::string newLabel);
};

#endif