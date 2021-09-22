#include "SettingsCommand.h"

void SettingsCommand::execute()
{
    DataManager *d = getDataManager();
    std::string out = "The current KNN parameters are: K = " + std::to_string(d->getK()) + ", distance metric = " + d->getDistMetricName() + "\n";
    getDIO()->write(out);

    std::string in = getDIO()->read();

    // If the user entered an empty input, we do not change any of the settings
    if (in.empty() || in == Socket::ENTER)
    {
        return;
    }

    // Split the string the user entered by spaces
    std::vector<std::string> results = StringFunctions::split(in, " ");

    // If didn't Recieve 2 parameters
    if (results.size() != 2)
    {
        getDIO()->write("please enter 2 parameters: <K> <distance metric>, press ENTER to return to main menu\n");
        getDIO()->read();
        return;
    }

    std::string kChosen = results[0];
    std::string distMetricChosen = results[1];

    // If k is not an int, or doesn't have a valid int value (too big or too small)
    if (!InputValidator::isInt(kChosen) || !d->setK(std::stoi(kChosen)))
    {
        getDIO()->write("invalid value for K, press ENTER to return to main menu\n");
        getDIO()->read();
        return;
    }

    // If the distance metric chosen is not supported
    if (!d->setDistMetricByName(distMetricChosen))
    {
        getDIO()->write("invalid distance metric, press ENTER to return to main menu\n");
        getDIO()->read();
        return;
    }
}