#include "Algorithm.h"

template <class T>
void Algorithm<T>::sortByDiffrence(std::vector<std::shared_ptr<T>> &v, const T &x)
{
    // last thing to implement

    std::multimap<double, std::shared_ptr<T>> m;
    // Store values in a multimap with the difference
    // with X as key
    for (int i = 0; i < v.size(); i++)
        m.insert(std::make_pair(abs(v[i]->getDistance(x)), v[i]));

    // Update the values of array
    int i = 0;
    for (auto const &x : m)
    {
        v[i++] = x.second;
    }
    //return v;
}

template <class T>
std::vector<std::shared_ptr<T>> Algorithm<T>::getKSmallest(std::vector<std::shared_ptr<T>> &sorted, int k)
{
    std::vector<std::shared_ptr<T>> kSmallest(sorted.begin(), sorted.begin() + k);
    return kSmallest;
}

template class Algorithm<Classified>;