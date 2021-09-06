#include "SettingCommand.h"

// To check if a string consists of digits only.
bool isNumber(const std::string &str)
{
    for (char const &c : str)
    {
        if (std::isdigit(c) == 0)
            return false;
    }
    return true;
}

void SettingsCommand::execute()
{
    DataManager *d = getDataManager();
    std::string out = "The current KNN parameters are: K = " + std::to_string(d->getK());
    +", distance metric = " + d->getDistMetricName();
    getDIO()->write(out);

    std::string in = getDIO()->read();
    // Split the string the user entered by spaces.
    std::istringstream iss(in);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

    // If didn't Recieve 2 parameters
    if (results.size() != 2)
    {
        getDIO()->write("please enter 2 parameters: <K> <distance metric>");
    }

    std::string kChosen = results[0];
    std::string distMetricChosen = results[1];

    // If k is not a int, or not doesn't have a valid int value (too big or too small).
    if (!isNumber(kChosen) || !d->setK(std::stoi(kChosen)))
    {
        getDIO()->write("invalid value for K");
    }

    // If the distance metric chosen is not supported.
    if (!d->setDistMetricByName(distMetricChosen))
    {
        getDIO()->write("invalid distance metric");
    }
}