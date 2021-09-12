#include "DisplayCommand.h"

void DisplayCommand::execute()
{
    DataManager *d = getDataManager();
    // The results to display
    std::vector<std::shared_ptr<Classified>> classified = d->getClassifiedData();


    // If the classified vector is empty - meaning we didn't classify the objects yet.
    if (classified.empty())
    {
        getDIO()->write("please classify the data uploaded");
        return;
    }

    int i = 1;
    // Display the results
    for (auto const &f : classified)
    {
        getDIO()->write(std::to_string(i) + "\t" + f->getLabel());
        i++;
    }
    getDIO()->write("Done.");
    // Wait for the user to press "enter", then continue to the Commands menu
    getDIO()->read();
}