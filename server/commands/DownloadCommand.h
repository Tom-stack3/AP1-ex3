#ifndef DOWNLOAD_COMMAND_H
#define DOWNLOAD_COMMAND_H

#include "Command.h"
#include "../../utils/Writer.h"
#include "../../utils/Reader.h"


#define DESCRIPTION "download results"

class DownloadCommand : public Command
{
public:
    // constructor.
    DownloadCommand(DefaultIO *dio, DataManager *dataManager) : Command(DESCRIPTION, dio, dataManager) {}

    /**
     * Execute the command.
     */
    void execute();
};

#undef DESCRIPTION
#endif