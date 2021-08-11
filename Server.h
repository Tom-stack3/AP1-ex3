#ifndef SERVER_H
#define SERVER_H
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
class Server
{
public:

    // initialize the socket.
    virtual void init(const int IDV)=0;

    // binding the socket IP to the socket port.
    virtual void bindSocket(std::string sourceIP,  const int sourcePort)=0;

    // somthing.
    virtual void acceptSocket()=0;
    
    // sending a messege to the client.
    virtual void sendSocket(const char *messege) = 0;

    // receiving a messege from the client.
    virtual void recvSocket(char *buffer, size_t len) = 0;

    // closing the socket.
    virtual void closeSocket() = 0;


};
#endif