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
    Socket& server = s;

    
    server.init(AF_INET);
    server.bindSocket("127.0.0.1", 7444);

    while(true){
        std::cout << "Wating for client" << std::endl;
        server.acceptSocket();
        std::cout << "Client is connected!" << std::endl;
        server.sendSocket("Im Ready to get messeges");
        char buffer [10000] = {0};
        server.recvSocket(buffer, 10000);
        std::cout << "Text File From Client: " << std::endl << buffer << std::endl;

        // create a csv from the input the user entered.
        Writer w = Writer(std::string("./server_data/input.csv"));
        w.write(buffer);
    }
    
}