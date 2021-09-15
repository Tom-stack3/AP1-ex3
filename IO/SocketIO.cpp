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
    char buffer[Socket::BUFFER_SIZE];

    getSocket()->recvSocket(buffer, sizeof(buffer));
    return buffer;
}

void SocketIO::write(std::string str) const
{
    getSocket()->sendSocket(str);
}

std::string SocketIO::getIOKind() const
{
    return SocketIO::KIND;
}
