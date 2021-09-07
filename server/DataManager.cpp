#include "DataManager.h"

DataManager::DataManager()
{
    // Set the default distance metric
    setDistMetricByName(DEFAULT_DISTANCE_METRIC);
}

int DataManager::getK()
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

std::vector<Command *> DataManager::getCommandsVector() const
{
    return m_commands;
}

void DataManager::addCommand(Command *commandPtr)
{
    m_commands.push_back(commandPtr);
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

DataManager::distMetric *DataManager::getDistMetric()
{
    return &m_dist;
}

void DataManager::setDistMetric(DataManager::distMetric met)
{
    m_dist = met;
}

std::string DataManager::getDistMetricName() const
{
    if (m_dist == &EucDistance::getDist)
    {
        return "EUC";
    }
    else if (m_dist == &ManDistance::getDist)
    {
        return "MAN";
    }
    else if (m_dist == &CheDistance::getDist)
    {
        return "CHE";
    }
    else
    {
        perror("Error! unknown distance metric function used.");
        return "UNKNOWN";
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
        // if the distance metric name recieved is not supported.
        return 0;
    }
    return 1;
}