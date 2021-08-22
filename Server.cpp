#include "Server.h"

int main(int argc, char **argv)
{

    // Create a new abstract Socket.
    Socket *server;
    Tcp t;
    Udp u;

    // Port number the server is going to run on.
    int port;

    // If recieved no communication protocol. (Udp/Tcp)
    if (argc < 2)
    {
        std::cout << "Error! Please enter a communication protocol (Udp/Tcp)" << std::endl;
        exit(1);
    }

    std::string protocolChosen = std::string(argv[1]);
    // convert the protocol chosen to lower case
    std::for_each(protocolChosen.begin(), protocolChosen.end(), [](char &c)
                  { c = ::tolower(c); });

    // Making the Socket pointer point to the right protocol.
    if (protocolChosen == "tcp")
    {
        std::cout << "Server is working with Tcp Protocol." << std::endl;
        t = Tcp{};
        server = &t;
        port = 54269;
    }
    else if (protocolChosen == "udp")
    {
        std::cout << "Server is working with Udp Protocol." << std::endl;
        u = Udp{};
        server = &u;
        port = 56942;
    }
    else
    {
        std::cout << "Error! Please choose a valid communication protocol (Udp/Tcp)" << std::endl;
        exit(1);
    }

    server->init(AF_INET);
    server->bindSocket("127.0.0.1", port);

    while (true)
    {
        std::cout << "Wating for client..." << std::endl;
        server->acceptSocket();
        std::cout << "Client is connected!" << std::endl;

        // If we are running a TCP server, the server should send a Welcome message.
        if (protocolChosen == "tcp")
        {
            server->sendSocket("Im Ready to get messeges - Enter input path");
        }

        char input[1000] = {0};
        server->recvSocket(input, sizeof(input));

        // If the client chose the other server.
        // We end the communication with the current client and start waiting for another client.
        if (strcmp(input, "didnt_choose_you") == 0)
        {
            continue;
        }
        // If the client-side had an error interacting with the client.
        // We end the communication with the current client and start waiting for another client.
        if (strcmp(input, "client_error") == 0)
        {
            continue;
        }

        // Create a csv from the input the user entered.
        Writer w = Writer(std::string("./server_data/input.csv"));
        w.write(input);

        // Create a new Reader instance
        Reader r = Reader(std::string("./server_data/classified.csv"));
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

        for (auto const &f : unclassifiedFlowers)
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
        server->sendSocket(output);
        std::cout << std::endl
                  << "Sent the classified objects back to the client!" << std::endl
                  << std::endl;
    }
}
