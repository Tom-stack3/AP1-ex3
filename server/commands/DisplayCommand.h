#ifndef DISPLAY_COMMAND_H
#define DISPLAY_COMMAND_H

#include "Command.h"
#include "../../utils/Reader.h"

#define DESCRIPTION "display results"

class DisplayCommand : public Command
{
public:
    // constructor.
    DisplayCommand(DefaultIO *dio, DataManager *dataManager) : Command(DESCRIPTION, dio, dataManager) {}

    /**
     * Execute the command.
     */
    void execute();
};

#undef DESCRIPTION
#endif