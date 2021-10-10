#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include "../../IO/DefaultIO.h"
#include "../DataManager.h"

class Command
{
private:
    std::string m_description;
    DefaultIO *m_dio;
    DataManager *m_dataManager;

public:
    // constructor
    Command(std::string description, DefaultIO *dio, DataManager *dataManager);

    /**
     * Get a const reference to the command description.
     */
    const std::string &getDescription() const;

    /**
     * Get a pointer to the data manager.
     */
    DataManager *getDataManager();

    /**
     * Get a const reference to the dio.
     */
    const DefaultIO *getDIO();

    /**
     * Execute the command.
     */
    virtual void execute() = 0;
};

#endif