#ifndef TCP_SERVER_H
#define TCP_SERVER_H
#include "Tcp.h"

class TcpServer
{
private:
    Tcp m_tcp;

public:
    static const int SERVER_PORT = 55556;
    /**
     * Initialize the Tcp Server.
     */
    void init(const int ipV);

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