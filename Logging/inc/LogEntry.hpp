#ifndef LOGENTRY_HPP
#define LOGENTRY_HPP

#include <string>
// This header file contains the log_entry itself which is MESSAGE and LEVEL.

enum class Level { DEBUG = 0, INFO = 1, WARN = 2, ERROR = 3, FATAL = 4 };

class LogEntry {
private:
  Level level;
  std::string message;
  static std::string levelToString(Level level);

public:
  LogEntry(Level level, const std::string &msg);
  std::string toString() const;
  Level getLevel() const { return level; }
  const std::string &getMessage() const { return message; }
};

#endif