#ifndef DEFAULT_IO_H
#define DEFAULT_IO_H

#include <string>

class DefaultIO
{
public:
    /**
     * Read.
     */
    virtual std::string read() const = 0;

    /**
     * Write.
     */
    virtual void write(std::string) const = 0;
};
#endif