#include "CLI.h"


CLI::CLI(DefaultIO *dio, DataManager *data)
{
    m_dio = dio;
    m_data = data;

    DisplayCommand disp = DisplayCommand(dio, m_data);
    ClassifyCommand classify = ClassifyCommand(dio, m_data);
    ConfusionMatrixCommand confusionMatrix = ConfusionMatrixCommand(dio, m_data);
    SettingsCommand settings = SettingsCommand(dio, m_data);
    UploadCommand upload = UploadCommand(dio, m_data);
    DownloadCommand download = DownloadCommand(dio, m_data);

    m_commands.push_back(upload);
    m_commands.push_back(settings);
    m_commands.push_back(classify);
    m_commands.push_back(disp);
    m_commands.push_back(download);
    m_commands.push_back(confusionMatrix);
}

CLI::CLI(DefaultIO *dio, DataManager *data, std::vector<Command> commands)
{
    m_dio = dio;
    m_data = data;
    m_commands = commands;
}

void CLI::start()
{
    int i = 1;
    m_dio->write("Welcome to the KNN Classifier Server. Please choose an option:");
    for (Command &command : m_commands)
    {
        m_dio->write(i + ". " + command.getDescription());
    }
}
