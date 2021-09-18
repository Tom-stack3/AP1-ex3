#include "DownloadCommand.h"

void DownloadCommand::execute()
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

    getDIO()->write("Please insert path.\n");
    std::string path = getDIO()->read();

    // compilation problem:
    Writer writer = Writer(std::string(path));
    writer.write(Reader::getLablesString(d->getClassifiedData()));
}