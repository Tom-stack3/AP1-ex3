#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "../classifier/Classified.h"
#include <vector>
#include <iterator>
#include <map>

class DataManager
{
private:
    int m_k;
    std::vector<std::shared_ptr<Classified>> m_trainData;
    std::vector<std::shared_ptr<Classified>> m_testData;
    std::vector<std::shared_ptr<Classified>> m_classifiedData;
    double (*m_dist)(const Classified &, const Classified &);

public:
    typedef double (*distMetric)(const Classified &, const Classified &);
    
    // getter and setter for k
    int getK();
    void setK(int k);

    // getter and setter for train data
    std::vector<std::shared_ptr<Classified>> getTrainData();
    void setTrainData(std::vector<std::shared_ptr<Classified>> data);

    // getter and setter for test data
    std::vector<std::shared_ptr<Classified>> getTestData();
    void setTestData(std::vector<std::shared_ptr<Classified>> data);

    // getter and setter for classified data
    std::vector<std::shared_ptr<Classified>> getClassifiedData();
    void setClassifiedData(std::vector<std::shared_ptr<Classified>> data);

    // getter and setter for dist function pointer
    distMetric getDistMetric();
    void setDistMetric(distMetric ds);
};

#endif