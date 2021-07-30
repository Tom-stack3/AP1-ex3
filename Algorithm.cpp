#include "Algorithm.h"

template <class T>
std::vector<T> Algorithm<T>::sortByDiffrence(std::vector<T> v, T x)
{
    std::multimap<int, T> m;
    // Store values in a multimap with the difference
    // with X as key
    for (int i = 0; i < v.size(); i++)
        m.insert(std::make_pair(abs(v[i].getDistance(x)), v[i]));

    // Update the values of array
    int i = 0;
    for (auto const &x : m)
    {
        v[i++] = x.second;
    }
    return v;
}

template <class T>
std::vector<T> Algorithm<T>::getKSmallest(std::vector<T> sorted, int k)
{
    std::vector<T> kSmallest(sorted.begin(), sorted.begin() + k);
    return kSmallest;
}

template class Algorithm<Flower>;