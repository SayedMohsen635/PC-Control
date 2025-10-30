#include "../inc/LaunchAppAction.hpp"
#include <algorithm>

ActionResult LaunchAppAction::execute(const Command &cmd) {
  std::string app = cmd.getApp();
  app.erase(std::remove_if(app.begin(), app.end(), ::isspace), app.end());

  if (app.empty()) {
    return ActionResult("No specified app\n", false);
  }

  pid_t child = fork();

  if (child == 0) {
    if (app == "Chrome") {
      std::cout << "[Action] Launching App: " + app << std::endl;
      execlp("google-chrome", "google-chrome", nullptr);
    } else if (app == "Firefox") {
      std::cout << "[Action] Launching App: " + app << std::endl;
      execlp("firefox", "firefox", nullptr); /* Check */
    } else if (app == "Calculator") {
      std::cout << "[Action] Launching App: " + app << std::endl;
      execlp("gnome-calculator", "gnome-calculator", nullptr);
    } else {
      return ActionResult("Unknown Application\n", false);
    }
  } else if (child < 0) {
    std::cout << "Failed to fork process" << std::endl;
  }

  return ActionResult("Application Launched: " + app + '\n', true);
}