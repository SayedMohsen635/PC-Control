#include "../inc/ActionHandler.hpp"
#include "../inc/LaunchAppAction.hpp"

ActionResult ActionHandler::handleCommand(const Command &cmd) {
  if (cmd.getCommand() == "LAUNCH") {
    LaunchAppAction action;
    return action.execute(cmd);
  } else if (cmd.getCommand() == "EXIT") {
    return ActionResult("Good Bye", true);
  } else {
    return ActionResult("Unknown Command: " + cmd.getCommand(), false);
  }
}