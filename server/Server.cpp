#include "Server.h"

void handleClient(int connectionSocket, std::vector<int> *sockets)
{
    Tcp clientSocket;
    Tcp *clientSocket_ptr = &clientSocket;
    clientSocket.init(AF_INET, connectionSocket);
    // Add the socket descriptor to the sockets vector
    sockets->push_back(connectionSocket);

    Classified::distMetric euc = &EucDistance::getDist;
    DataManager d = DataManager();
    d.setDistMetric(euc);
    SocketIO soc = SocketIO(clientSocket_ptr);

    DefaultIO *dio = &soc;

    CLI c = CLI(dio, &d);
    c.start();

    clientSocket.closeSocket();
    // Remove the socket descriptor from the sockets vector
    remove(sockets->begin(), sockets->end(), connectionSocket);
}

int main()
{
    int port = TcpServer::SERVER_PORT;

    TcpServer server = TcpServer();
    server.init(AF_INET);
    server.bindSocket("127.0.0.1", port);
    std::vector<int> clientSockets;

    while (true)
    {
        std::cout << "Wating for client..." << std::endl;
        int socketWithClient = server.acceptSocket();
        // Meaning the timeout was reached, without any clients trying to connect
        if (socketWithClient == -1)
        {
            std::cout << "Timeout has been reached!" << std::endl;
            break;
        }

        std::cout << "Client is connected!" << std::endl;

        // We create a new Thread for handling the client
        std::thread handlingClient(handleClient, socketWithClient, &clientSockets);
        handlingClient.detach();
    }

    // While we are not finished serving all the clients
    while (!clientSockets.empty())
    {
    }

    std::cout << "Shutting down" << std::endl;
    server.closeSocket();
    std::cout << "Exiting" << std::endl;
    return 0;
}