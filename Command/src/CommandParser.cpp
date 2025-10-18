#include "../inc/CommandParser.hpp"

Command parse(const std::string &clientRequest)
{
    auto symbol = clientRequest.find('|');

    if (symbol == std::string::npos)
    {
        return Command();
    }

    std::string com = clientRequest.substr(0, symbol);
    std::string arg = clientRequest.substr(symbol + 1);
    return Command(com, arg);
}