#include <iostream>
#include <string>
#include <array>
#include "Flower.h"
#include "Writer.h"

int main()
{
    // creating and working with a new instance of flower.
    std::array<int, 4> n = {1, 2, 3, 4};
    Flower f = Flower(n, "Flower_");
    std::cout << f.getLabel() << f.getProperties()[2] << std::endl;
    // setting a new label for the flower.
    f.setLabel(std::string("Flower_1"));
    std::cout << f.getLabel() << f.getProperties()[2] << std::endl;

    Flower f2 = Flower(n, "Flower_2");
    std::vector<Flower> v{f, f2, f, f2, f, f, f, f2};

    // write the flowers
    Writer w = Writer(std::string("../test.csv"));
    w.write(v);
}