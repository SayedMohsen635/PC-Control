#include "../inc/ResponseGenerator.hpp"

std::string ResponseGenerator::generate(const ActionResult &result) {
  return (result.getSuccess() ? "OK|" : "ERROR|") + result.getMessage();
}
