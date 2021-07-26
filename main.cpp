#include <iostream>
#include <string>
#include <array>
#include "Flower.h"
#include "Writer.h"
#include "Reader.h"

// TODO - when writing 5.0 it is written as 5 instead of 5.0

int main()
{
    // creating and working with a new instance of flower.
    std::array<double, 4> n = {1.5, 2.6, 3.9, 69};
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

    // read from the data file
    Reader r = Reader(std::string("../data/classified.csv"));
    std::vector<Flower> vf = r.read();
    // iterate through the flowers read
    for (Flower const &flower : vf)
    {
        const std::array<double, 4> &prop = flower.getProperties();
        // print the flower
        //std::cout << prop[0] << "," << prop[1] << "," << prop[2] << "," << prop[3] << "," << flower.getLabel() << std::endl;
    }
    w.write(vf);
}