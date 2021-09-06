#include "Command.h"

Command::Command(std::string description, DefaultIO *dio){
    m_description = std::move(description);
    m_dio = dio;
}

const std::string &Command::getDescription() const{
    return m_description;
}