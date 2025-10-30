#include "../inc/ActionHandler.hpp"
#include <sys/types.h>
#include <unistd.h>

class LaunchAppAction : public Action {
public:
  LaunchAppAction() {}
  ActionResult execute(const Command &cmd) override;
};