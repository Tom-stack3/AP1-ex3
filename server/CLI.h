#ifndef CLI_H
#define CLI_H
#include "../server/commands/Command.h"
#include "../server/commands/ClassifyCommand.h"
#include "../server/commands/ConfusionMatrixCommand.h"
#include "../server/commands/DisplayCommand.h"
#include "../server/commands/SettingsCommand.h"
#include "../server/commands/UploadCommand.h"
#include "../server/commands/DownloadCommand.h"
#include "../server/commands/ExitCommand.h"
#include "../IO/DefaultIO.h"
#include "../IO/StandardIO.h"
#include "../IO/SocketIO.h"
#include "../utils/InputValidator.h"

class CLI
{
private:
    DefaultIO *m_dio;
    DataManager *m_data;
    std::vector<std::shared_ptr<Command>> m_commands;

public:
    static constexpr const char *EXIT_CODE = "EXIT";

    // Constructors
    CLI(DefaultIO *dio, DataManager *data);

    CLI(DefaultIO *dio, DataManager *data, std::vector<std::shared_ptr<Command>> commands);

    /**
     * Write the menu of commands.
     */
    void printMenu();

    /**
     * Write the start message.
     */
    void start();

    /**
     * 
     */
    void communicateWithUser();

    /*
    * Returns the menu as a string.
    */
    std::string getMenu();

    /**
     * Validate user input, when entering command number.
     * Returns true if the input is valid, false - otherwise.
     */
    bool validateUserInput(const std::string &);
};

#endif