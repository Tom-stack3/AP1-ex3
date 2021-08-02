#include "main.h"

int main()
{
    // Create a new Reader instance
    Reader r = Reader(std::string("../data/classified.csv"));
    // Read and load the Classified Flowers
    std::vector<std::unique_ptr<Classified>> classifiedObjects;
    r.read(classifiedObjects);

    // Change the reader path to the path of the Unclassified Flowers
    r.setInputPath(std::string("../data/Unclassified.csv"));
    // Read and load the Unclassified Flowers
    std::vector<std::unique_ptr<Classified>> unclassifiedFlowers;
    r.read(unclassifiedFlowers);

    const int k = 5;
    // Create a new KNNClassifier
    KNNClassifier knn(classifiedFlowers, k);
    Classifier& classifier = knn;

    for (std::unique_ptr<Classified> f : unclassifiedFlowers)
    {
        // Set the flowers label to the prediction the Model made
        f->setLabel(classifier.predict(*f));
    }

    // Create a new Writer
    Writer w = Writer(std::string("../output_changed.csv"));
    // Write the newly classified Flowers to the output file.
    // The flowers in "unclassifiedFlowers" vector are now classified.
    w.write(unclassifiedFlowers);
}