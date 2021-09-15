#ifndef SOCKET_IO_H
#define SOCKET_IO_H

#include "DefaultIO.h"
#include "../protocol/Socket.h"
#include "../protocol/Tcp.h"

class SocketIO : public DefaultIO
{

private:
    // Socket to send and get messeges from client.
    Tcp *socket;

public:
    /**
    * Constructor.
    */
    SocketIO(Tcp *socket);

    /**
     * Read.
     */
    std::string read() const;

    /**
     * Write.
     */
    void write(std::string) const;

    /**
     * Get socket function.
     */
    Tcp *getSocket() const;

    /**
     * Set socket function.
     */
    void setSocket(Tcp *s);

    /**
     * get IO kind such as standard, socket ..
     */
    std::string getIOKind() const;
};
#endif
