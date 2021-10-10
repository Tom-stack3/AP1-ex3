#ifndef SERVER_H
#define SERVER_H
#include "../classifier/Classified.h"
#include "../classifier/Classifier.h"
#include "../classifier/KNNClassifier.h"

#include "../utils/Writer.h"
#include "../utils/Reader.h"

#include "../protocol/Socket.h"
#include "../protocol/Tcp.h"
#include "../protocol/TcpServer.h"

#include "DataManager.h"
#include "CLI.h"

#include "../IO/SocketIO.h"
#include "../IO/DefaultIO.h"
#include "../IO/StandardIO.h"

#include <iostream>
#include <algorithm>
#include <thread>

class Server
{
private:
    int m_port;
    TcpServer m_server;
    std::vector<int> m_clientSockets;

    void handleClient(int connectionSocket);

public:
    // Constructor.
    Server();

    void start();
};

int main();

#endif