#ifndef LOGGINGSYSTEM_HPP
#define LOGGINGSYSTEM_HPP

#include "LogEntry.hpp"
#include <vector>
// This header file contains all the functions that the logging system should
// support for the log itself.

class LoggingSystem {
private:
  static std::vector<LogEntry> logs;

public:
  static void log(Level level, const std::string &message);

  static void Debug(const std::string &message);
  static void Info(const std::string &message);
  static void Warn(const std::string &message);
  static void Error(const std::string &message);
  static void Fatal(const std::string &message);

  static int GetLogCount();
  static void Dump();
};

#endif
