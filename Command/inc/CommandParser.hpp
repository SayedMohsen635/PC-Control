#ifndef COMMANDPARSER_HPP
#define COMMANDPARSER_HPP

#include "Command.hpp"

class CommandParser
{
public:
    static Command parse(const std::string &clientRequest);
};

#endif