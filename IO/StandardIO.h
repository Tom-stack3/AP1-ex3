#ifndef STANDARD_IO_H
#define STANDARD_IO_H

#include "DefaultIO.h"
#include <iostream>

class StandardIO : public DefaultIO
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