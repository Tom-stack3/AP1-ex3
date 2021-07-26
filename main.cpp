#include  <iostream>
#include<string>
#include<array>
#include "Flower.h"

int main(){
    // creating and working with a new instance of flower.
    std::array<int, 4> n = {1, 2, 3, 4};
    Flower f = Flower(n, "Flower_");
    std::cout << f.getLabel() << f.getProperties()[2] << std::endl;
    // setting a new label for the flower.
    f.setLabel(std::string("hi?"));
    std::cout << f.getLabel() << f.getProperties()[2] << std::endl;
}