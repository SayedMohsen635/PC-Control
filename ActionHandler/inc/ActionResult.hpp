#ifndef ACTIONRESULT_HPP
#define ACTIONRESULT_HPP

#include <string>

class ActionResult {
private:
  bool success;
  std::string message;

public:
  ActionResult(const std::string &msg = "", bool succ = false)
      : success(succ), message(msg) {}
  std::string getMessage() const { return message; }
  bool getSuccess() const { return success; }
};

#endif