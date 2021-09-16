#ifndef TCP_H
#define TCP_H
#include "Socket.h"

class Tcp : public Socket
{
private:
    // the socket used to communicate with the other socket.
    int m_connectionSocket;

public:
    void init(const int ipV);

    void connectSocket(const char *destIp, const int destPort);

    int acceptSocket();

    void sendSocket(std::string message);

    void recvSocket(char *buffer, int len);
};
#endif