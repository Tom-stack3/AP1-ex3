#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "../classifier/Classified.h"
#include <vector>
#include <iterator>
#include <map>

class DataManager
{
private:
    int m_K;
    std::vector<std::shared_ptr<Classified>> m_trainData;
    std::vector<std::shared_ptr<Classified>> m_testData;
    std::vector<std::shared_ptr<Classified>> m_classifiedData;
    double (*m_dist)(const Classified &, const Classified &);


public:
    typedef double (*distMetric)(const Classified &, const Classified &);
};

#endif