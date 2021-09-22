#include "ExitCommand.h"

void ExitCommand::execute()
{
    getDataManager()->setExitStatus(true);
    getDIO()->write(CLI::EXIT_CODE);
}