#ifndef TCP_H
#define TCP_H
#include "Socket.h"

class Tcp : public Socket
{
private:
    // The socket used to communicate with the other socket.
    int m_connectionSocket;
    // The size of the queue to accept clients.
    int m_queueSize = 10;

public:
    void init(const int ipV);

    void connectSocket(const char *destIp, const int destPort);

    int acceptSocket();

    void sendSocket(std::string message);

    void recvSocket(char *buffer, int len);

    void setQueueSize(int s);
};
#endif