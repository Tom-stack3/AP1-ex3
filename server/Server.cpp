#include "Server.h"

void handleClient(int connectionSocket)
{
    Tcp clientSocket;
    Tcp *clientSocket_ptr = &clientSocket;

    clientSocket.init(AF_INET, connectionSocket);

    Classified::distMetric euc = &EucDistance::getDist;
    DataManager d = DataManager();
    d.setDistMetric(euc);
    SocketIO soc = SocketIO(clientSocket_ptr);

    DefaultIO *dio = &soc;

    CLI c = CLI(dio, &d);
    c.start();

    clientSocket.closeSocket();
}

int main()
{
    int port = TcpServer::SERVER_PORT;

    TcpServer server = TcpServer();
    server.init(AF_INET);
    server.bindSocket("127.0.0.1", port);

    while (true)
    {
        std::cout << "Wating for client..." << std::endl;
        int socketWithClient = server.acceptSocket();
        std::cout << "Client is connected!" << std::endl;

        // We create a new Thread for handling the client.
        std::thread handlingClient(handleClient, socketWithClient);
        handlingClient.detach();
    }
}
