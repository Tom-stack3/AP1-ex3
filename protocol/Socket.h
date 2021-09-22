#ifndef SOCKET_H
#define SOCKET_H
#include <string>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

class Socket
{
private:
    int m_socketNum;
    // the ip version. either AF_INET or AF_INET6.
    int m_ipV;

protected:
    /**
     * Set the Ip version.
     */
    void setIpV(const int ipV);
    /**
     * Get the Ip version
     */
    int getIpV() const;
    /**
     * Set the socket number.
     */
    void setSocketNum(const int socket);

public:
    // Buffer size
    static const int BUFFER_SIZE = 8192;

    // String to represent ENTER
    static constexpr const char *ENTER = "ENTER";

    /**
     * Binding the socket IP to the socket port.
     */
    void bindSocket(const char *sourceIp, const int sourcePort);

    /**
     * Close the socket.
     */
    void closeSocket();

    /**
     * Initialize the socket.
     */
    virtual void init(const int ipV) = 0;

    /**
     * Connect to a socket.
     */
    virtual void connectSocket(const char *destIp, const int destPort) = 0;

    /**
     *Listen for incoming sockets.
     */
    virtual void listenSocket() = 0;

    /**
     * Accept an incoming socket.
     */
    virtual int acceptSocket() = 0;

    /**
     * Sending a messege to another socket.
     */
    virtual void sendSocket(std::string message) = 0;

    /**
     * Receiving a messege from another socket.
     */
    virtual void recvSocket(char *buffer, int len) = 0;

    /**
     * Get the socket number.
     */
    int getSocketNum() const;
};
#endif