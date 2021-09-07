#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "../classifier/Classified.h"
#include <vector>
#include <iterator>
#include <map>

class DataManager
{
private:
    const int MIN_K_VALUE = 1;
    const int MAX_K_VALUE = 10;
    const int DEFAULT_K = 5;
    const std::string DEFAULT_DISTANCE_METRIC = "EUC";

    int m_k = DEFAULT_K;
    // Data
    std::vector<std::shared_ptr<Classified>> m_trainData;
    std::vector<std::shared_ptr<Classified>> m_testData;
    std::vector<std::shared_ptr<Classified>> m_classifiedData;
    // Distance metric
    double (*m_dist)(const Classified &, const Classified &);

public:
    typedef double (*distMetric)(const Classified &, const Classified &);

    // constructor.
    DataManager();

    /**
     * Get K used.
     */
    int getK();
    /**
     * Set K used.
     * 
     * Returns 1 if valid change, 0 if not.
     */
    int setK(int k);
    
    /**
     * Get train data.
     */
    std::vector<std::shared_ptr<Classified>> getTrainData() const;
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

    /**
     * Get the name of the distance metric function used.
     */
    std::string getDistMetricName() const;

    /**
     * Set the distance metric function used by name.
     * 
     * Returns 1 if valid change, 0 if not.
     */
    int setDistMetricByName(std::string distMetricName);
};

#endif