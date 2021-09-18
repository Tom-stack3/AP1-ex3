#include "Client.h"

int main()
{
    Tcp tcp = Tcp{};
    tcp.init(AF_INET);
    tcp.connectSocket("127.0.0.1", TcpServer::SERVER_PORT);
    std::string userInput;

    while (true)
    {
        char buffer[Socket::BUFFER_SIZE] = {0};
        tcp.recvSocket(buffer, sizeof(buffer));
        std::cout << buffer;
        std::getline(std::cin, userInput);
        tcp.sendSocket(userInput);

        if (userInput.compare("1") == 0)
        {
            // Train data
            tcp.recvSocket(buffer, Socket::BUFFER_SIZE);
            std::cout << buffer << std::endl;
            std::getline(std::cin, userInput);
            // Send the contents of the train file to the server
            tcp.sendSocket(Reader::fileToString(userInput));

            // Test data
            tcp.recvSocket(buffer, Socket::BUFFER_SIZE);
            std::cout << buffer << std::endl;
            std::getline(std::cin, userInput);
            // Send the contents of the test file to the server
            tcp.sendSocket(Reader::fileToString(userInput));

            // Write the second "Upload complete."
            tcp.recvSocket(buffer, Socket::BUFFER_SIZE);
            std::cout << buffer << std::endl;
        }
    }
    tcp.closeSocket();
}
