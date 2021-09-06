#ifndef SOCKET_IO_H
#define SOCKET_IO_H

#include "DefaultIO.h"
#include "../protocol/Socket.h"
#include "../protocol/Tcp.h"

class SocketIO : public DefaultIO
{
public:
    /**
     * Read.
     */
    std::string read() const;

    /**
     * Write.
     */
    void write(std::string) const;
};
#endif
