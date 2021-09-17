#include "CLI.h"

CLI::CLI(DefaultIO *dio, DataManager *data)
{
    m_dio = dio;
    m_data = data;

    std::vector<std::shared_ptr<Command>> commands;
    commands.push_back(std::make_shared<UploadCommand>(dio, data));
    commands.push_back(std::make_shared<SettingsCommand>(dio, data));
    commands.push_back(std::make_shared<ClassifyCommand>(dio, data));
    commands.push_back(std::make_shared<DisplayCommand>(dio, data));
    commands.push_back(std::make_shared<DownloadCommand>(dio, data));
    commands.push_back(std::make_shared<ConfusionMatrixCommand>(dio, data));

    m_commands = commands;
}

CLI::CLI(DefaultIO *dio, DataManager *data, std::vector<std::shared_ptr<Command>> commands)
{
    m_dio = dio;
    m_data = data;
    m_commands = commands;
}

void CLI::printMenu()
{
    int i = 1;
    std::string menu = "";
    for (auto const &command : m_commands)
    {
        menu += (std::to_string(i) + ". " + (*command).getDescription() + "\n");
        i++;
    }
    m_dio->write(menu);
}

void CLI::communicateWithUser()
{
    while (true)
    {
        std::string res = m_dio->read();
        // need to validate the input.
        int choise = std::stoi(res) - 1;
        m_commands.at(choise)->execute();
        printMenu();
    }
}

std::string CLI::getMenu()
{
    int i = 1;
    std::string menu = "";
    for (auto const &command : m_commands)
    {
        menu += (std::to_string(i) + ". " + (*command).getDescription() + "\n");
        i++;
    }
    return menu;
}

void CLI::start()
{
    m_dio->write("Welcome to the KNN Classifier Server. Please choose an option:\n" + getMenu());
    communicateWithUser();
}
