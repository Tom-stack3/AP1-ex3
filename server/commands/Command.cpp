#include "Command.h"

Command::Command(std::string description, DefaultIO *dio, DataManager *dataManager)
{
    m_description = std::move(description);
    m_dio = dio;
    m_dataManager = dataManager;
}

const std::string &Command::getDescription() const
{
    return m_description;
}

DataManager *Command::getDataManager()
{
    return m_dataManager;
}

const DefaultIO *Command::getDIO()
{
    return m_dio;
}