#include "Server.h"

void Server::handleClient(int connectionSocket)
{
    Tcp client;
    Tcp *client_ptr = &client;
    client.init(AF_INET, connectionSocket);
    // Add the socket descriptor to the sockets vector
    m_clientSockets.push_back(connectionSocket);

    Classified::distMetric euc = &EucDistance::getDist;
    DataManager d = DataManager();
    d.setDistMetric(euc);
    SocketIO soc = SocketIO(client_ptr);

    DefaultIO *dio = &soc;

    CLI c = CLI(dio, &d);
    c.start();

    client_ptr->closeSocket();
    // Remove the socket descriptor from the sockets vector
    m_clientSockets.erase(std::remove(m_clientSockets.begin(), m_clientSockets.end(), connectionSocket), m_clientSockets.end());
}

Server::Server()
{
    int m_port = TcpServer::SERVER_PORT;

    m_server = TcpServer();
    m_server.init(AF_INET);
    m_server.bindSocket("127.0.0.1", m_port);
    std::vector<int> m_clientSockets;
}

void Server::start()
{
    while (true)
    {
        std::cout << "Wating for clients..." << std::endl;
        int socketWithClient = m_server.acceptSocket();
        // Meaning the timeout was reached, without any clients trying to connect
        if (socketWithClient == TcpServer::TIMEOUT_ERROR)
        {
            std::cout << "Timeout has been reached!" << std::endl;
            break;
        }

        std::cout << "A client connected!" << std::endl;

        // We create a new Thread for handling the client
        std::thread handlingClient(&Server::handleClient, this, socketWithClient);
        handlingClient.detach();
    }

    // While we are not finished serving all the clients
    while (!m_clientSockets.empty())
    {
    }

    std::cout << "Shutting down..." << std::endl;
    m_server.closeSocket();
    std::cout << "Exiting" << std::endl;
}

int main()
{
    Server s;
    s.start();
}