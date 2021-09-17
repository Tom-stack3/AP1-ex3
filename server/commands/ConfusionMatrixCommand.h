#ifndef CONFUSION_MATRIX_COMMAND_H
#define CONFUSION_MATRIX_COMMAND_H

#include "Command.h"
#include <map>

#define DESCRIPTION "display algorithm confusion matrix"

class ConfusionMatrixCommand : public Command
{
private:
    /**
     * Print the confusion matrix.
     */
    void m_printMatrix(std::vector<std::vector<double>> matrix, std::vector<std::string> labels, DataManager *d);

public:
    // constructor.
    ConfusionMatrixCommand(DefaultIO *dio, DataManager *dataManager) : Command(DESCRIPTION, dio, dataManager) {}

    /**
     * Execute the command.
     */
    void execute();
};

#undef DESCRIPTION
#endif