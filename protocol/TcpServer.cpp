#include "TcpServer.h"

void TcpServer::bindSocket(const char *sourceIp, const int sourcePort)
{
    m_tcp.bindSocket(sourceIp, sourcePort);
    // Start listening for connections
    m_tcp.listenSocket();
}

void TcpServer::init(const int ipV)
{
    m_tcp;
    m_tcp.init(ipV);
}

int TcpServer::acceptSocket()
{
    int sock = m_tcp.getSocketNum();

    struct timeval tv;
    memset(&tv, 0, sizeof(tv));
    // Timeout in seconds
    tv.tv_sec = TcpServer::TIMEOUT_IN_SECONDS;

    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(sock, &readfds);

    // If an Error occured
    if (select(sock + 1, &readfds, NULL, NULL, &tv) < 0)
    {
        perror("select error");
    }
    // If a connection has been made to connect to the server, and the Timeout hasn't passed yet
    if (FD_ISSET(sock, &readfds))
    {
        // Accept the client that made the connection
        return m_tcp.acceptSocket();
    }
    // Else, the Timeout has passed
    return TcpServer::TIMEOUT_ERROR;
}

void TcpServer::closeSocket()
{
    m_tcp.closeSocket();
}