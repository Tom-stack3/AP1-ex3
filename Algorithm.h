#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "Flower.h"
#include <vector>
#include <map>

template <class T>
class Algorithm
{
public:
    /**
     * Sort the vector.
     */
    std::vector<T> sortByDiffrence(std::vector<T> v, T x);

    /**
     * Return the K smallest elements.
     */
    std::vector<T> getKSmallest(std::vector<T> sorted, int k);
};

#endif