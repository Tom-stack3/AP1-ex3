#ifndef TCP_H
#define TCP_H
#include "Socket.h"

class Tcp : public Socket
{
private:
    // the other socket this socket needs to interact with.
    int otherSocket;
public:
    void init(const int ipV);

    void connectSocket(const char* destIp, const int destPort);

    void acceptSocket();

    void sendSocket(std::string message);

    void recvSocket(char *buffer, int len);
};
#endif