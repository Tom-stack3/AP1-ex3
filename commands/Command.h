#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include "../IO/DefaultIO.h"

class Command
{
private:
    std::string m_description;
    DefaultIO *m_dio;

public:
    // constructor
    Command(std::string description, DefaultIO *dio);

    /**
     * Get a const reference to the command description.
     */
    const std::string &getDescription() const;

    /**
     * Execute the command.
     */
    virtual void execute() = 0;
};

#endif