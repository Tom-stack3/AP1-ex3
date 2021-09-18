#include "ConfusionMatrixCommand.h"

void ConfusionMatrixCommand::execute()
{
    DataManager *d = getDataManager();
    // The classified data by the algorithm
    std::vector<std::shared_ptr<Classified>> classified = d->getClassifiedData();
    // The test data
    std::vector<std::shared_ptr<Classified>> test = d->getTestData();

    // If the classified vector is empty - meaning we didn't classify the objects yet.
    if (classified.empty())
    {
        getDIO()->write("please classify the data uploaded, press ENTER to return to main menu\n");
        getDIO()->read();
        return;
    }

    std::vector<std::string> labels = d->getTestLabels();
    std::map<std::string, int> labelsMap;

    for (int i = 0; i < labels.size(); i++)
    {
        labelsMap.insert(std::pair<std::string, int>(labels[i], i));
    }

    // The labels guessed by the classifier
    std::vector<std::string> classifiedLabels;
    // The correct labels from the test data
    std::vector<std::string> correctLabels;

    for (auto const &f : classified)
    {
        classifiedLabels.push_back(f->getLabel());
    }
    for (auto const &f : test)
    {
        correctLabels.push_back(f->getLabel());
    }

    std::vector<std::vector<double>> matrix;
    // Fill the matrix with zeros
    for (int i = 0; i < labels.size(); i++)
    {
        std::vector<double> v(labels.size(), 0.0);
        matrix.push_back(v);
    }

    // Fill the matrix with the number of guesses
    for (int i = 0; i < correctLabels.size(); i++)
    {
        matrix[labelsMap[correctLabels[i]]][labelsMap[classifiedLabels[i]]]++;
    }

    // Calculate percentages and put them in the matrix
    for (int row = 0; row < labels.size(); row++)
    {
        // Calculate the number of objects of that kind (by summing the row)
        int rowSum = 0;
        for (const auto &f : matrix[row])
        {
            rowSum += f;
        }

        // Write percentages in the matrix instead of amount of objects
        for (int col = 0; col < labels.size(); col++)
        {
            matrix[row][col] = (matrix[row][col] / rowSum) * 100;
        }
    }
    // Write the cofusion matrix
    m_printMatrix(matrix, labels, d);

    // Wait for the user to press "Enter", then continue to the Commands menu
    getDIO()->read();
}

void ConfusionMatrixCommand::m_printMatrix(std::vector<std::vector<double>> matrix, std::vector<std::string> labels, DataManager *d)
{
    std::string matrixString = "";
    for (int row = 0; row < labels.size(); row++)
    {
        std::string line = labels[row];
        for (const auto &f : matrix[row])
        {
            line += "\t" + std::to_string(f) + "%";
        }
        matrixString += line + "\n";
    }

    std::string out = "The current KNN parameters are: K = " + (std::to_string(d->getK()) + ", distance metric = " + d->getDistMetricName() + "\n press ENTER to return to main menu\n");
    getDIO()->write(matrixString + out);
}