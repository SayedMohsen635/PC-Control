#include "../inc/Server.hpp"
#include <cstdio>

// set port number
Server::Server(int port) : port(port), serverSocket(-1) {}

// initialize socket and bind
bool Server::setupSocket() {
  serverSocket = socket(AF_INET, SOCK_STREAM, 0);

  // server address
  sockaddr_in serverAddress;
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(port);
  serverAddress.sin_addr.s_addr = INADDR_ANY;

  // reuse the same port
  int opt = 1;
  setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

  // binding socket
  int bindResult =
      bind(serverSocket, (sockaddr *)&serverAddress, sizeof(serverAddress));
  if (bindResult < 0) {
    perror("Bind failed");
    return false;
  }

  // listen to the clients
  if (listen(serverSocket, 5) < 0) {
    perror("Listen Failed");
    return false;
  }

  return true;
}

// wait for a client and process a single request
std::string Server::handleClient(int clientSocket) {
  // receiving data from client
  char buffer[1024] = {0};
  recv(clientSocket, buffer, sizeof(buffer), 0);
  return processRequest(buffer);
}

// used in handleClient function to process the raw data from the client
std::string Server::processRequest(const std::string &request) {
  std::cout << "The client's message is : " << request << std::endl;
  return "OK|Request Received";
}

// listen and handle client requests
void Server::start() {
  std::cout << "[Server] Starting on port " << port << "...\n";

  if (!setupSocket()) {
    std::cerr << "[Server] Failed to set up socket" << std::endl;
    return;
  }

  std::cout << "[Server] Listening for client connections...\n";

  // accept the requet
  int clientSocket = accept(serverSocket, nullptr, nullptr);
  if (clientSocket < 0) {
    perror("Accept Failed");
    return;
  }

  std::string msg = Server::handleClient(clientSocket);
  send(clientSocket, msg.c_str(), msg.size(), 0);
  close(clientSocket);
}

// close the server
Server::~Server() { close(serverSocket); }