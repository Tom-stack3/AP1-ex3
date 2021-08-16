#include "main.h"

int main()
{
    /*
    // Create a new Reader instance
    Reader r = Reader(std::string("../data/classified.csv"));
    // Read and load the Classified Flowers
    std::vector<std::shared_ptr<Classified>> classifiedObjects;
    r.read(classifiedObjects);

    // Change the reader path to the path of the Unclassified Flowers
    r.setInputPath(std::string("../data/Unclassified.csv"));
    // Read and load the Unclassified Flowers
    std::vector<std::shared_ptr<Classified>> unclassifiedFlowers;
    r.read(unclassifiedFlowers);

    const int k = 5;
    // Create a new KNNClassifier
    KNNClassifier knn(classifiedObjects, k);
    Classifier& classifier = knn;

    for (const std::shared_ptr<Classified>& f : unclassifiedFlowers)
    {
        // Set the classified object label to the prediction the Model made
        f->setLabel(classifier.predict(*f));
    }

    // Create a new Writer
    Writer w = Writer(std::string("../output.csv"));
    // Write the newly classified Flowers to the output file.
    // The flowers in "unclassifiedFlowers" vector are now classified.
    w.write(unclassifiedFlowers);
    */

    Tcp s{};
    Socket &server = s;

    server.init(AF_INET);
    server.bindSocket("127.0.0.1", 54269);

    while (true)
    {
        std::cout << "Wating for client..." << std::endl;
        server.acceptSocket();
        std::cout << "Client is connected!" << std::endl;
        server.sendSocket("Im Ready to get messeges - Enter input path");
        char input[1000] = {0};
        server.recvSocket(input, sizeof(input));

        // Create a csv from the input the user entered.
        Writer w = Writer(std::string("./server_data/input.csv"));
        w.write(input);

        // Create a new Reader instance
        Reader r = Reader(std::string("./data/classified.csv"));
        // Read and load the Classified Flowers
        std::vector<std::shared_ptr<Classified>> classifiedObjects;
        r.read(classifiedObjects);

        // Change the reader path to the path of the Unclassified Flowers
        r.setInputPath(std::string("./server_data/input.csv"));
        // Read and load the Unclassified Flowers
        std::vector<std::shared_ptr<Classified>> unclassifiedFlowers;
        r.read(unclassifiedFlowers);

        const int k = 5;
        // Create a new KNNClassifier
        KNNClassifier knn(classifiedObjects, k);
        Classifier &classifier = knn;

        for (const std::shared_ptr<Classified> &f : unclassifiedFlowers)
        {
            // Set the classified object label to the prediction the Model made
            f->setLabel(classifier.predict(*f));
        }

        // Write the labels classified.
        w.setOutputPath("./server_data/clients_output.csv");
        w.write(unclassifiedFlowers);
        r.setInputPath("./server_data/clients_output.csv");
        std::string output = r.toString();
        // Send the client the labels classified.
        server.sendSocket(output);
        std::cout << std::endl
                  << "Sent the classified objects back to the client!" << std::endl
                  << std::endl;
    }
}
