#ifndef DEFAULT_IO_H
#define DEFAULT_IO_H

#include <string>

class DefaultIO
{
public:
    /**
     * Read.
     */
    virtual std::string read() = 0;

    /**
     * Write.
     */
    virtual void write(std::string) = 0;
};
#endif