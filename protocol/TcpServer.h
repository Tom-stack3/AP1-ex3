#ifndef TCP_SERVER_H
#define TCP_SERVER_H
#include "Tcp.h"

class TcpServer
{
private:
    Tcp m_tcp;

public:
    static const int SERVER_PORT = 55556;
    static const int TIMEOUT_IN_SECONDS = 120;
    static const int TIMEOUT_ERROR = -1;

    /**
     * Initialize the Tcp Server.
     */
    void init(const int ipV);

    /**
     * Binding the socket IP to the socket port.
     */
    void bindSocket(const char *sourceIp, const int sourcePort);

    /**
     * Accept an incoming socket.
     */
    int acceptSocket();

    /**
     * Close the socket.
     */
    void closeSocket();
};
#endif