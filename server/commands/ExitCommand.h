#ifndef EXIT_COMMAND_H
#define EXIT_COMMAND_H

#include "Command.h"
#include "../CLI.h"

#define DESCRIPTION "exit"

class ExitCommand : public Command
{
public:
    // constructor.
    ExitCommand(DefaultIO *dio, DataManager *dataManager) : Command(DESCRIPTION, dio, dataManager) {}

    /**
     * Execute the command.
     */
    void execute();
};

#undef DESCRIPTION
#endif