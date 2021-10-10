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
    commands.push_back(std::make_shared<ExitCommand>(dio, data));

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
    m_dio->write(getMenu());
}

void CLI::communicateWithUser()
{
    while (true)
    {
        std::string res = m_dio->read();
        // If the input from the user is valid.
        if (validateUserInput(res))
        {
            int choise = std::stoi(res) - 1;
            m_commands.at(choise)->execute();

            // If the user wants to exit
            if (m_data->getExitStatus())
            {
                break;
            }

            printMenu();
        }
        else
        {
            m_dio->write("\nPlease Enter a Valid choice from the menu:\n" + getMenu());
        }
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

bool CLI::validateUserInput(const std::string &input)
{
    // If input is not a String.
    if (!InputValidator::isInt(input))
    {
        return false;
    }
    int choise = std::stoi(input);
    // If the int is too big or too small.
    if (choise < 1 || choise > m_commands.size())
    {
        return false;
    }
    return true;
}