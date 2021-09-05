#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <vector>
#include <iterator>
#include <map>
#include "Classified.h"
template <class T>
class Algorithm
{
public:
    /**
     * Sort the vector.
     */
    void sortByDiffrence(std::vector<std::shared_ptr<T>> &v, const T &x);

    /**
     * Return the K smallest elements.
     */
    std::vector<std::shared_ptr<T>> getKSmallest(std::vector<std::shared_ptr<T>> &sorted, int k);
};

#endif