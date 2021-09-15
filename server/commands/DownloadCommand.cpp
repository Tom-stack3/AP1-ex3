#include "DownloadCommand.h"

void DownloadCommand::execute()
{
    getDIO()->write("Please insert path.");
    std::string outputPath = getDIO()->read();

}