#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include "Socket.h"

class Tcp : public Socket
{
public:
    Tcp (){}
    void init(const int ipV);

    void connectSocket(const char* destIp, const int destPort);

    void acceptSocket();

    void sendSocket(std::string message);

    void recvSocket(char *buffer, int len);
};
#endif