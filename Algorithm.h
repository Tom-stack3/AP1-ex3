#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <vector>
#include <iterator>
#include <map>

template <class T>

class Algorithm
{
public:
    // return k smallest elements.
    std::vector<T> sortByDiffrence(std::vector<T> v, T x)
    {
        std::multimap<int, T> m;
        typename std::multimap<int, T>::iterator it;
        // Store values in a map with the difference
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

    std::vector<T> getKSmallest(std::vector<T> sorted, int k)
    {
        std::vector<T> kSmallest(sorted.begin(), sorted.begin() + k);
        return kSmallest;
    }
};

#endif