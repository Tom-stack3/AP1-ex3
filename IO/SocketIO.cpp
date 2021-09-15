#include "SocketIO.h"

SocketIO::SocketIO(Tcp *s)
{
    setSocket(s);
}

void SocketIO::setSocket(Tcp *s)
{
    socket = s;
}

Tcp *SocketIO::getSocket() const
{
    return socket;
}

std::string SocketIO::read() const
{
    char buffer[10000];
    getSocket()->recvSocket(buffer, sizeof(buffer));
    return buffer;
}

void SocketIO::write(std::string str) const
{
    getSocket()->sendSocket(str);
}
