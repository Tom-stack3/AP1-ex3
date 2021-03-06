#ifndef STANDARD_IO_H
#define STANDARD_IO_H

#include "DefaultIO.h"
#include <iostream>

class StandardIO : public DefaultIO
{
public:
    static constexpr const char *KIND = "standard";

    /**
     * Read.
     */
    std::string read() const;

    /**
     * Write.
     */
    void write(std::string) const;

    /**
     * get IO kind such as standard, socket ..
     */
    std::string getIOKind() const;
};
#endif