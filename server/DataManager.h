#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "../classifier/Classified.h"
#include <vector>
#include <iterator>
#include <map>
#include <algorithm>

class DataManager
{
private:
    const int MIN_K_VALUE = 1;
    const int MAX_K_VALUE = 10;
    const int DEFAULT_K = 5;
    const std::string DEFAULT_DISTANCE_METRIC = "EUC";

    int m_k = DEFAULT_K;
    int m_lastKUsed = DEFAULT_K;
    // Data
    std::vector<std::shared_ptr<Classified>> m_trainData;
    std::vector<std::shared_ptr<Classified>> m_testData;
    std::vector<std::shared_ptr<Classified>> m_classifiedData;
    // Distance metrics
    Classified::distMetric m_dist;
    Classified::distMetric m_lastDistUsed;
    // If true, the user wanted to exit
    bool m_didExit = false;

public:
    // constructor.
    DataManager();

    /**
     * Get LastUsed K used.
     */
    int getLastUsedK() const;
    /**
     * Set LastUsed K used.
     */
    void setLastUsedK(int k);

    /**
     * True if user wants to exit, false otherwise.
     */
    bool getExitStatus() const;
    /**
     * Set Exit Status: True if user wants to exit, false otherwise.
     */
    void setExitStatus(bool);

    /**
     * Get K used.
     */
    int getK() const;
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
    Classified::distMetric *getLastUsedDistMetric();

    /**
     * Set distance metric.
     */
    void setLastUsedDistMetric(Classified::distMetric ds);

    /**
     * Get pointer to the pointer to the distance metric function.
     */
    Classified::distMetric *getDistMetric();

    /**
     * Set distance metric.
     */
    void setDistMetric(Classified::distMetric ds);

    /**
     * Get the name of the distance metric function received in the params.
     */
    std::string getDistMetricName(Classified::distMetric) const;

    /**
     * Set the distance metric function used by name.
     * 
     * Returns 1 if valid change, 0 if not.
     */
    int setDistMetricByName(std::string distMetricName);

    /**
     * Get a vector of all the different labels of the objects in the test data.
     */
    std::vector<std::string> getTestLabels() const;
};

#endif