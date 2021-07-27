#include <iostream>
#include <string>
#include <array>
#include "Flower.h"
#include "Writer.h"
#include "Reader.h"
#include "KNNClassifier.h"
int main()
{
    // creating and working with a new instance of flower.
    std::array<double, 4> n = {1.5, 2.6, 3.9, 69};
    std::array<double, 4> n2 = {1, 2, 3, 4};
    std::array<double, 4> n3 = {5.6,2.5,3.9,1.1};
    Flower f = Flower(n, "setosa");
    //std::cout << f.getLabel() << f.getProperties()[2] << std::endl;
    // setting a new label for the flower.
    f.setLabel(std::string("setosa"));
    //std::cout << f.getLabel() << f.getProperties()[2] << std::endl;

    Flower f2 = Flower(n2, "virginica");
    std::vector<Flower> v{f, f2, f, f2, f, f, f, f2};

    // write the flowers
    Writer w = Writer(std::string("../test.csv"));
    //w.write(v);

    // read from the data file
    Reader r = Reader(std::string("../data/classified.csv"));
    std::vector<Flower> vf = r.read();
    // iterate through the flowers read
    for (Flower const &flower : vf)
    {
        const std::array<double, 4> &prop = flower.getProperties();
        //print the flower
        //std::cout << prop[0] << "," << prop[1] << "," << prop[2] << "," << prop[3] << "," << flower.getLabel() << std::endl;
    }

    // test for the classifier
    Reader ur = Reader(std::string("../data/Unclassified.csv"));
    std::vector<Flower> uvf = ur.read();
    std::vector<Flower> output;
    KNNClassifier knn(vf);
  
    for (Flower const &flower : uvf)
    {    
        Flower f(flower.getProperties(), knn.predict(flower));
        output.push_back(f);
    }
    
    w.write(output);

}