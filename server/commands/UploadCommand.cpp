#include "UploadCommand.h"

void UploadCommand::execute()
{
    getDIO()->write("Please upload your local train CSV file.");
    if (getDIO()->getIOKind().compare(STANDARD_KIND))
    {
        // know that the input is a path
    }

    if (getDIO()->getIOKind().compare(SOCKET_KIND))
    {
        // know that the input is a string contains the contents of a file
    }
}