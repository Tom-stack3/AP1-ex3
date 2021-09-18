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
    return m_tcp.acceptSocket();
}

void TcpServer::closeSocket()
{
    m_tcp.closeSocket();
}