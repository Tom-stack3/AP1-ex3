#ifndef TCP_H
#define TCP_H
#include "Socket.h"
#include <cstring>

class Tcp : public Socket
{
private:
    // The socket used to communicate with the other socket.
    int m_connectionSocket;
    // The size of the queue to accept clients.
    int m_queueSize = 10;

public:
    /**
     * Initialize from an already existing socket number.
     */
    void init(const int ipV, int connectionSocket);

    /**
     * Initialize a new Socket.
     */
    void init(const int ipV);

    void connectSocket(const char *destIp, const int destPort);

    void listenSocket();

    int acceptSocket();

    void sendSocket(std::string message);

    void recvSocket(char *buffer, int len);

    void setQueueSize(int s);
};
#endif