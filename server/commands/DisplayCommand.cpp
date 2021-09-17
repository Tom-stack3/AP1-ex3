#include "DisplayCommand.h"

void DisplayCommand::execute()
{
    DataManager *d = getDataManager();
    // The results to display
    std::vector<std::shared_ptr<Classified>> classified = d->getClassifiedData();

    // If the classified vector is empty - meaning we didn't classify the objects yet.
    if (classified.empty())
    {
        getDIO()->write("please classify the data uploaded, press ENTER to return to main menu\n");
        getDIO()->read();
        return;
    }

    int i = 1;
    // Display the results
    std::string list = "";
    for (auto const &f : classified)
    {
        list += (std::to_string(i) + "\t" + f->getLabel() + "\n");
        i++;
    }

    getDIO()->write(list + "Done.\npress ENTER to return to main menu\n");
    // Wait for the user to press "Enter", then continue to the Commands menu
    getDIO()->read();
}