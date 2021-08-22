#include "Client.h"

int main()
{
    // Create a new Socket.
    Socket *chosenSocket = nullptr;
    Tcp tcp = Tcp{};
    Udp udp = Udp{};

    tcp.init(AF_INET);
    udp.init(AF_INET);
    // Connect to both servers.
    tcp.connectSocket("127.0.0.1", 54269);
    udp.connectSocket("127.0.0.1", 56942);

    char buffer[50] = {0};

    // Recieve the welcome message from the TCP server.
    tcp.recvSocket(buffer, sizeof(buffer));

    std::cout << "From server:" << buffer << std::endl;

    // Get the input from the client. In the following format: x y z
    // x: the communication protocol wanted (UDP/TCP)
    // y: the path to the unclassified data (.csv file)
    // z: the path to output and save the labels classified by the server
    // for example: UDP ./data/Unclassified.csv ./outputFromServer.csv
    std::string userInput;
    getline(std::cin, userInput);

    // Split the string the user entered by spaces.
    std::istringstream iss(userInput);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

    // If didn't Recieve 3 parameters
    if (results.size() != 3)
    {
        std::cout << "Error! Please enter 3 parameters in the right format:" << std::endl
                  << "[Udp/Tcp] [path to unclassified data] [path to output]" << std::endl;
        // We infrom the server that the client-side had an error interacting with the client.
        udp.sendSocket("client_error");
        tcp.sendSocket("client_error");
        exit(1);
    }

    std::string protocolChosen = results[0];
    std::string unclassifiedInputPath = results[1];
    std::string outputPath = results[2];

    // convert the protocol chosen to lower case
    std::for_each(protocolChosen.begin(), protocolChosen.end(), [](char &c)
                  { c = ::tolower(c); });

    // Making the Socket pointer point to the right protocol.
    if (protocolChosen == "tcp")
    {
        chosenSocket = &tcp;
        udp.sendSocket("didnt_choose_you");
    }
    else if (protocolChosen == "udp")
    {
        chosenSocket = &udp;
        tcp.sendSocket("didnt_choose_you");
    }
    else
    {
        std::cout << "Error! Please choose a valid communication protocol (Udp/Tcp)" << std::endl;
        // We infrom the server that the client-side had an error interacting with the client.
        udp.sendSocket("client_error");
        tcp.sendSocket("client_error");
        exit(1);
    }
    // Read and send the server the unclassified flowers.
    Reader r = Reader(unclassifiedInputPath);
    std::string str = r.toString();
    chosenSocket->sendSocket(str);

    char outputBuffer[1000] = {0};
    // Recieve the classified labels from the server.
    chosenSocket->recvSocket(outputBuffer, 1000);

    // Write the labels recieved to the wanted output path.
    Writer w = Writer(outputPath);
    w.write(outputBuffer);

    // Close both sockets.
    udp.closeSocket();
    tcp.closeSocket();
}
