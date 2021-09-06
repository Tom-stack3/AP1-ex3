#include "DataManager.h"

int DataManager::getK()
{
    return m_k;
}

void DataManager::setK(int m_K)
{
    m_k = m_k;
}

std::vector<std::shared_ptr<Classified>> DataManager::getTrainData()
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

void DataManager::setClassifiedData(std::vector<std::shared_ptr<Classified>> m_classifiedData)
{
    m_classifiedData = m_classifiedData;
}

DataManager::distMetric *DataManager::getDistMetric()
{
    return &m_dist;
}

void DataManager::setDistMetric(DataManager::distMetric met)
{
    m_dist = met;
}
