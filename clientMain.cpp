#include "clientMain.h"

int main()
{
    // Create a new Socket.
    Tcp cl{};
    Socket &client = cl;
    client.init(AF_INET);
    // Connect to the server.
    client.connectSocket("127.0.0.1", 49152);

    char buffer[50] = {0};
    // Recieve the welcome message.
    client.recvSocket(buffer, sizeof(buffer));

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

    std::string protocolWanted = results[0];
    std::string unclassifiedInputPath = results[1];
    std::string outputPath = results[2];

    // Read and send the server the unclassified flowers.
    Reader r = Reader(unclassifiedInputPath);
    std::string str = r.toString();
    client.sendSocket(str);

    char outputBuffer[1000] = {0};
    // Recieve the classified labels from the server.
    client.recvSocket(outputBuffer, 1000);

    // Write the labels recieved to the wanted output path.
    Writer w = Writer(outputPath);
    w.write(outputBuffer);

    // Close the socket.
    client.closeSocket();
}
