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
        // Receive input from the server
        tcp.recvSocket(buffer, sizeof(buffer));

        // If the communication with the server has ended
        if (strcmp(buffer, CLI::EXIT_CODE) == 0)
        {
            break;
        }

        std::cout << buffer;
        std::getline(std::cin, userInput);

        // if the user entered ENTER (\n)
        if (userInput.length() == 0)
        {
            tcp.sendSocket(Socket::ENTER);
        }
        else
        {
            // Send the server the Command the user entered
            tcp.sendSocket(userInput);
        }

        // If the user chose the first command we need to send the content of the file instead of the path.
        // (that is why there is a speciel if statement for it)

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
