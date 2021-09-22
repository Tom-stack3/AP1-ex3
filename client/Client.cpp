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
            std::string content;

            // Train data
            tcp.recvSocket(buffer, Socket::BUFFER_SIZE);
            std::cout << buffer << std::endl;
            std::getline(std::cin, userInput);
            try
            {
                content = Reader::fileToString(userInput);
            }
            catch (const std::runtime_error& e)
            {
                content = TcpServer::CLIENT_ERROR;
                tcp.sendSocket(content);
                // Display the Error message
                std::cerr << e.what() << std::endl;
                exit(1);
            }
            // Send the contents of the train file to the server
            tcp.sendSocket(content);

            // Test data
            tcp.recvSocket(buffer, Socket::BUFFER_SIZE);
            std::cout << buffer << std::endl;
            std::getline(std::cin, userInput);
            try
            {
                content = Reader::fileToString(userInput);
            }
            catch (const std::runtime_error& e)
            {
                content = TcpServer::CLIENT_ERROR;
                tcp.sendSocket(content);
                // Display the Error message
                std::cerr << e.what() << std::endl;
                exit(1);
            }
            // Send the contents of the test file to the server
            tcp.sendSocket(content);

            // Write the second "Upload complete."
            tcp.recvSocket(buffer, Socket::BUFFER_SIZE);
            std::cout << buffer << std::endl;
        }

        else if (userInput.compare("5") == 0)
        {
            tcp.recvSocket(buffer, Socket::BUFFER_SIZE);
            std::cout << buffer;
            // checking if the user classified before
            if (std::string(buffer).compare("please classify the data uploaded, press ENTER to return to main menu\n") == 0)
            {
                std::getline(std::cin, userInput);
                tcp.sendSocket(Socket::ENTER);
            }
            else
            {
                // Sending the path to server
                std::getline(std::cin, userInput);
                Writer writer = Writer(userInput);
                tcp.sendSocket(userInput);

                // Getting the classified lables from server
                tcp.recvSocket(buffer, Socket::BUFFER_SIZE);

                // Writing to path the classified lables.
                writer.write(buffer);

                // Sending enter to server
                tcp.sendSocket(Socket::ENTER);

                // Reading the ENTER messege from server
                tcp.recvSocket(buffer, Socket::BUFFER_SIZE);
                std::cout << buffer;

                // The user needs to press enter to return to main menu
                std::getline(std::cin, userInput);
                tcp.sendSocket(Socket::ENTER);
            }
        }
    }

    tcp.closeSocket();
}
