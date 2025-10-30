#ifndef SERVER_HPP
#define SERVER_HPP

#include "../../ActionHandler/inc/ActionResult.hpp"
#include "../../Command/inc/CommandParser.hpp"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>

class Server {
public:
  // set port number
  explicit Server(int port);

  // listen and handle client requests
  void start();

  // close the server
  ~Server();

private:
  int port;
  int serverSocket;

  // initialize socket and bind
  bool setupSocket();

  // wait for a client and process a single request
  ActionResult handleClient(int clientSocket);

  // used in handleClient function to process the raw data from the client
  ActionResult processRequest(const std::string &request);
};

#endif