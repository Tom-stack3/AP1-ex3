#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

class Client
{
public:

    virtual void init(const int ipV) = 0;

    virtual void bindSocket(const char* sourceIp, const int sourcePort) = 0;

    virtual void connectSocket( const char* destIp, const int destPort) = 0;

    virtual void sendSocket(std::string message) = 0;

    virtual void recvSocket(char *buffer, int len) = 0;

    virtual void closeSocket() = 0;
};
#endif