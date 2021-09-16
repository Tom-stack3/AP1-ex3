#ifndef UPLOAD_COMMAND_H
#define UPLOAD_COMMAND_H

#include "Command.h"
#include "../../utils/Reader.h"
#include "../../IO/SocketIO.h"
#include "../../IO/StandardIO.h"

#define DESCRIPTION "upload an unclassified csv data file"

class UploadCommand : public Command
{
public:
    // constructor.
    UploadCommand(DefaultIO *dio, DataManager *dataManager) : Command(DESCRIPTION, dio, dataManager) {}

    /**
     * Execute the command.
     */
    void execute();
};

#undef DESCRIPTION
#endif