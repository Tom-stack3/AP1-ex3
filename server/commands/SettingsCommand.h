#ifndef SETTINGS_COMMAND_H
#define SETTINGS_COMMAND_H

#include "Command.h"
#include "../../utils/InputValidator.h"
#include <sstream>

#define DESCRIPTION "algorithm settings"

class SettingsCommand : public Command
{
public:
    // constructor.
    SettingsCommand(DefaultIO *dio, DataManager *dataManager) : Command(DESCRIPTION, dio, dataManager) {}

    /**
     * Execute the command.
     */
    void execute();
};

#undef DESCRIPTION
#endif