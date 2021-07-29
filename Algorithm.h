#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <vector>
template <class T>

class Algorithm
{
public:
    // return k smallest elements.
    std::vector<T> select(int k, std::vector<T> arr, int l = 0, int r = -1);

    // sort the array based on the comparation with x. (smaller then x will be on the left of x, and the rest on the right of x)
    void partition(std::vector<T> arr, T x, int l = 0, int r = -1);
};

#endif