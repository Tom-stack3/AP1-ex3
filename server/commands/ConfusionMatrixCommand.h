#ifndef CONFUSION_MATRIX_COMMAND_H
#define CONFUSION_MATRIX_COMMAND_H

#include "Command.h"

#define DESCRIPTION "display algorithm confusion matrix"

class ConfusionMatrixCommand : public Command
{
public:
    // constructor.
    ConfusionMatrixCommand(DefaultIO *dio, DataManager *dataManager) : Command(DESCRIPTION, dio, dataManager) {}

    /**
     * Execute the command.
     */
    void execute();
};

#endif