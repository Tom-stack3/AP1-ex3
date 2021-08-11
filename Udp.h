#ifndef UDP_H
#define UDP_H
#include "Socket.h"

class Udp : public Socket
{
private:
    // the other socket this socket needs to interact with.
    struct sockaddr_in other;
public:
    void init(const int ipV);

    void connectSocket(const char* destIp, const int destPort);

    void acceptSocket();

    void sendSocket(std::string message);

    void recvSocket(char *buffer, int len);
};
#endif