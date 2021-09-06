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

    /**
     * Get K used.
     */
    int getK();
    /**
     * Set K used.
     */
    void setK(int k);

    /**
     * Get train data.
     */
    std::vector<std::shared_ptr<Classified>> getTrainData();
    /**
     * Set train data.
     */
    void setTrainData(std::vector<std::shared_ptr<Classified>> data);

    /**
     * Get test data.
     */
    std::vector<std::shared_ptr<Classified>> getTestData() const;
    /**
     * Set test data.
     */
    void setTestData(std::vector<std::shared_ptr<Classified>> data);

    /**
     * Get classified data.
     */
    std::vector<std::shared_ptr<Classified>> getClassifiedData() const;
    
    /**
     * Set classified data.
     */
    void setClassifiedData(std::vector<std::shared_ptr<Classified>> data);

    /**
     * Get pointer to the pointer to the distance metric function.
     */
    distMetric *getDistMetric();
    /**
     * Set distance metric.
     */
    void setDistMetric(distMetric ds);
};

#endif