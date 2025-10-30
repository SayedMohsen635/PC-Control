#include "../inc/CommandParser.hpp"

Command CommandParser::parse(const std::string &clientRequest) {
  auto symbol = clientRequest.find('|');

  std::string com = clientRequest;
  if (com.rfind("EXIT", 0) == 0) {
    return Command("EXIT");
  }

  if (symbol == std::string::npos) {
    return Command();
  }

  com = clientRequest.substr(0, symbol);
  std::string arg = clientRequest.substr(symbol + 1);

  return Command(com, arg);
}