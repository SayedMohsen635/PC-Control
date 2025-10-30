#ifndef ACTION_HPP
#define ACTION_HPP

#include "../../Command/inc/Command.hpp"
#include "ActionResult.hpp"

class Action {
public:
  ~Action() = default;

  virtual ActionResult execute(const Command &cmd) = 0;
};

#endif