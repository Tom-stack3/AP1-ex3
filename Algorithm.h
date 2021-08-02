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
    void sortByDiffrence(std::vector<std::unique_ptr<T>>& v, const T& x);

    /**
     * Return the K smallest elements.
     */
    std::vector<T> getKSmallest(std::vector<std::unique_ptr<T>> sorted, int k);
};

#endif