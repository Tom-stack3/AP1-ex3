#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include "Client.h"

class TcpClient : public Client
{
private:
int socketNum;
// the ip version. either AF_INET or AF_INET6.
int ipV;
public:
void init(const int ipV);

    void bindSocket(const char* sourceIp, const int sourcePort);

    void connectSocket(const char* destIp, const int destPort);

    void sendSocket(std::string message);

    void recvSocket(char *buffer, int len);

    void closeSocket();
};
#endif