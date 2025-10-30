#include "../inc/LaunchAppAction.hpp"
#include <algorithm>
#include <cstddef>
#include <sys/mman.h>
#include <sys/wait.h>

ActionResult LaunchAppAction::execute(const Command &cmd) {
  std::string app = cmd.getApp();
  app.erase(std::remove_if(app.begin(), app.end(), ::isspace), app.end());

  if (app.empty()) {
    return ActionResult("No specified app\n", false);
  }

  pid_t child = fork();
  int *shared = (int *)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
                            MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  *shared = 0;

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
      *shared = 1;
    }
  } else if (child < 0) {
    std::cout << "Failed to fork process" << std::endl;
  }

  wait(NULL); // Wait for the child to finish the process

  if (*shared == 1) {
    return ActionResult("Unknown Application\n", false);
  } else {
    return ActionResult("Application Launched: " + app + '\n', true);
  }
}