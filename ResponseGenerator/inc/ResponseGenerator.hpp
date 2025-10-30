#ifndef RESPONSEGENERATOR_HPP
#define RESPONSEGENERATOR_HPP

#include "../../ActionHandler/inc/ActionResult.hpp"
#include <string>

class ResponseGenerator {
public:
  ResponseGenerator() = default;

  static std::string generate(const ActionResult &result);
};

#endif