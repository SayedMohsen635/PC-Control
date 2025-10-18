#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>

class Command
{
private:
    std::string comName;
    std::string application;

public:
    Command(const std::string &com = "", const std::string &app = "") : comName(com), application(app) {};

    std::string getCommand() const { return comName; }
    std::string getApp() const { return application; }

    bool isValid() const { return !comName.empty(); }
};

#endif