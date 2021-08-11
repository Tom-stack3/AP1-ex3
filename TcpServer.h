#ifndef TCP_SERVER_H
#define TCP_SERVER_H
#include "Server.h"


class TcpServer : public Server
{
    int socketNum;
    int socketPort;
    int clientSocket;
public:
    // constructor (passing the socket port as argument).
    TcpServer();

    // initialize the socket.
     void init(const int IDV);

    // binding the socket IP to the socket port.
     void bindSocket(std::string sourceIP, const int sourcePort);

    // somthing.
     void acceptSocket();
    
    // sending a messege to the client.
     void sendSocket(const char *messege);

    // receiving a messege from the client.
     void recvSocket(char *buffer, size_t len);

    // closing the socket.
     void closeSocket();

};

#endif