#include "../inc/Server.hpp"
#include "../../ActionHandler/inc/ActionHandler.hpp"
#include "../../Logging/inc/LoggingSystem.hpp"
#include "../../ResponseGenerator/inc/ResponseGenerator.hpp"

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
    LoggingSystem::Error("Bind Failed\n");
    // perror("Bind failed");
    return false;
  }

  // listen to the clients
  if (listen(serverSocket, 5) < 0) {
    LoggingSystem::Error("Listen Failed\n");
    // perror("Listen Failed");
    return false;
  }

  return true;
}

// wait for a client and process a single request
ActionResult Server::handleClient(int clientSocket) {
  // receiving data from client
  char buffer[1024] = {0};
  recv(clientSocket, buffer, sizeof(buffer), 0);
  return processRequest(buffer);
}

// used in handleClient function to process the raw data from the client
ActionResult Server::processRequest(const std::string &request) {
  std::string req = request;
  req.erase(std::remove(req.begin(), req.end(), '\n'),
            req.end()); // Trimming new lines in the end of request

  Command result = CommandParser::parse(req);
  ActionHandler handleCmd;
  if (!result.isValid()) {
    return ActionResult("Invalid Format\n", false);
  }

  return handleCmd.handleCommand(result);
}

// listen and handle client requests
void Server::start() {
  LoggingSystem::Info("Starting on port ");
  std::cout << port << "...\n";

  if (!setupSocket()) {
    LoggingSystem::Error("Failed to set up socket\n");
    // std::cerr << "[Server] Failed to set up socket" << std::endl;
    return;
  }

  LoggingSystem::Info("Listening for client connections...\n");
  // std::cout << "[Server] Listening for client connections...\n";

  while (true) {
    // accept the request
    int clientSocket = accept(serverSocket, nullptr, nullptr);
    if (clientSocket < 0) {
      LoggingSystem::Error("Accept Failed\n");
      // perror("Accept Failed");
      continue;
    }

    LoggingSystem::Info("Client Connected\n");
    // std::cout << "[Server] Client Connected." << std::endl;

    while (true) {
      ActionResult msg = Server::handleClient(clientSocket);
      if (ResponseGenerator::generate(msg).empty()) {
        LoggingSystem::Info("Client Disconnected\n");
        // std::cout << "[Server] Client Disconnected";
        break;
      }

      send(clientSocket, ResponseGenerator::generate(msg).c_str(),
           ResponseGenerator::generate(msg).size(), 0);

      if (msg.getMessage() == "Good Bye") {
        LoggingSystem::Info("Closing connection for client.\n");
        // std::cout << "[Server] Closing connection for client." << std::endl;
        break;
      }
    }
    close(clientSocket);
  }
}

// close the server
Server::~Server() { close(serverSocket); }