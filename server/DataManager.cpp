#include "DataManager.h"

DataManager::DataManager()
{
    // Set the default distance metric
    setDistMetricByName(DEFAULT_DISTANCE_METRIC);
}

int DataManager::getLastUsedK() const
{
    return m_lastKUsed;
}

void DataManager::setLastUsedK(int k)
{
    m_lastKUsed = k;
}

bool DataManager::getExitStatus() const
{
    return m_didExit;
}

void DataManager::setExitStatus(bool b)
{
    m_didExit = b;
}

int DataManager::getK() const
{
    return m_k;
}

int DataManager::setK(int k)
{
    // If k is invalid
    if (k > MAX_K_VALUE || k < MIN_K_VALUE)
    {
        return 0;
    }
    m_k = k;
    return 1;
}

std::vector<std::shared_ptr<Classified>> DataManager::getTrainData() const
{
    return m_trainData;
}

void DataManager::setTrainData(std::vector<std::shared_ptr<Classified>> data)
{
    m_trainData = data;
}

std::vector<std::shared_ptr<Classified>> DataManager::getTestData() const
{
    return m_testData;
}

void DataManager::setTestData(std::vector<std::shared_ptr<Classified>> data)
{
    m_testData = data;
}

std::vector<std::shared_ptr<Classified>> DataManager::getClassifiedData() const
{
    return m_classifiedData;
}

void DataManager::setClassifiedData(std::vector<std::shared_ptr<Classified>> classifiedData)
{
    m_classifiedData = classifiedData;
}

Classified::distMetric *DataManager::getLastUsedDistMetric()
{
    return &m_lastDistUsed;
}

void DataManager::setLastUsedDistMetric(Classified::distMetric ds)
{
    m_lastDistUsed = ds;
}

Classified::distMetric *DataManager::getDistMetric()
{
    return &m_dist;
}

void DataManager::setDistMetric(Classified::distMetric met)
{
    m_dist = met;
}

std::string DataManager::getDistMetricName(Classified::distMetric met) const
{
    if (met == &EucDistance::getDist)
    {
        return "EUC";
    }
    else if (met == &ManDistance::getDist)
    {
        return "MAN";
    }
    else if (met == &CheDistance::getDist)
    {
        return "CHE";
    }
    else
    {
        throw std::runtime_error("Error! unknown distance metric function used.");
    }
}

int DataManager::setDistMetricByName(std::string distMetricName)
{
    if (distMetricName == "EUC")
    {
        setDistMetric(&EucDistance::getDist);
    }
    else if (distMetricName == "MAN")
    {
        setDistMetric(&ManDistance::getDist);
    }
    else if (distMetricName == "CHE")
    {
        setDistMetric(&CheDistance::getDist);
    }
    else
    {
        // If the distance metric name recieved is not supported.
        return 0;
    }
    // Everything went OK
    return 1;
}

std::vector<std::string> DataManager::getTestLabels() const
{
    std::vector<std::string> labels;
    // Loop over the test data
    for (auto const &cls : getTestData())
    {
        std::string currentLabel = (*cls).getLabel();
        // If the label is not in the labels vector
        if (std::find(labels.begin(), labels.end(), currentLabel) == labels.end())
        {
            // Add the label to the labels vector
            labels.push_back(currentLabel);
        }
    }
    return labels;
}

// sus