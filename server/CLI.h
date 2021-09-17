#ifndef CLI_H
#define CLI_H
#include <vector>
#include "../server/commands/Command.h"
#include "../server/commands/ClassifyCommand.h"
#include "../server/commands/ConfusionMatrixCommand.h"
#include "../server/commands/DisplayCommand.h"
#include "../server/commands/SettingsCommand.h"
#include "../server/commands/UploadCommand.h"
#include "../server/commands/DownloadCommand.h"
#include "../IO/DefaultIO.h"
#include "../IO/StandardIO.h"
#include "../IO/SocketIO.h"

class CLI
{
private:
    DefaultIO *m_dio;
    DataManager *m_data;
    std::vector<Command> m_commands;

public:
    CLI(DefaultIO *dio, DataManager *data);

    CLI(DefaultIO *dio, DataManager *data, std::vector<Command> commands);

    void start();
};

#endif