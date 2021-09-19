#include "TcpServer.h"

void TcpServer::bindSocket(const char *sourceIp, const int sourcePort)
{
    m_tcp.bindSocket(sourceIp, sourcePort);
}

void TcpServer::init(const int ipV)
{
    m_tcp;
    m_tcp.init(ipV);
}

int TcpServer::acceptSocket()
{
    struct timeval tv;
    memset(&tv, 0, sizeof(tv));
    // Timeout in seconds
    tv.tv_sec = TcpServer::TIMEOUT_IN_SECONDS;
    // Set the timeout for the Server socket
    setsockopt(m_tcp.getSocketNum(), SOL_SOCKET, SO_RCVTIMEO, (struct timeval *)&tv, sizeof(struct timeval));

    return m_tcp.acceptSocket();
}

void TcpServer::closeSocket()
{
    m_tcp.closeSocket();
}