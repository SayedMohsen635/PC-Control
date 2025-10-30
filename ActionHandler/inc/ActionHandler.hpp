#ifndef ACTIONHANDLER_HPP
#define ACTIONHANDLER_HPP

#include "../../Command/inc/Command.hpp"
#include "Action.hpp"
#include "ActionResult.hpp"
#include <iostream>

class ActionHandler {
public:
  static ActionResult handleCommand(const Command &cmd);
};

#endif