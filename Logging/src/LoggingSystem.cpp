#include "../inc/LoggingSystem.hpp"
#include <iostream>

std::vector<LogEntry> LoggingSystem::logs;

LogEntry::LogEntry(Level level, const std::string &msg)
    : level(level), message(msg) {}

std::string LogEntry::levelToString(Level level) {
  switch (level) {
  case Level::DEBUG:
    return "DEBUG";
  case Level::INFO:
    return "INFO";
  case Level::WARN:
    return "WARN";
  case Level::ERROR:
    return "ERROR";
  case Level::FATAL:
    return "FATAL";
  default:
    return "UNKNOWN";
  }
}

std::string LogEntry::toString() const {
  return "[" + levelToString(level) + "] " + message;
}

void LoggingSystem::log(Level level, const std::string &message) {
  std::cout << logs.emplace_back(level, message).toString();
}

void LoggingSystem::Debug(const std::string &message) {
  log(Level::DEBUG, message);
}

void LoggingSystem::Info(const std::string &message) {
  log(Level::INFO, message);
}

void LoggingSystem::Warn(const std::string &message) {
  log(Level::WARN, message);
}

void LoggingSystem::Error(const std::string &message) {
  log(Level::ERROR, message);
}

void LoggingSystem::Fatal(const std::string &message) {
  log(Level::FATAL, message);
}

void LoggingSystem::Dump() {
  for (const auto &msg : logs) {
    std::cout << msg.toString() << std::endl;
  }
}

int LoggingSystem::GetLogCount() { return static_cast<int>(logs.size()); }
