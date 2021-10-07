#ifndef CLASSIFY_COMMAND_H
#define CLASSIFY_COMMAND_H

#include "Command.h"
#include "../../classifier/Classifier.h"
#include "../../classifier/KNNClassifier.h"
#include <thread>

#define DESCRIPTION "classify data"

class ClassifyCommand : public Command
{
public:
    // constructor.
    ClassifyCommand(DefaultIO *dio, DataManager *dataManager) : Command(DESCRIPTION, dio, dataManager) {}

    /**
     * Execute the command.
     */
    void execute();
};

#undef DESCRIPTION
#endif