#pragma once
#include "entity.hpp"
#include <string>
#include <vector>

namespace mcpp
{
inline int dp_version;
inline std::string dp_description;
inline std::string dp_namespace;
void init();
std::string generate_mcmeta();
std::string generate_function_tag(std::string function);
void func(std::string name, std::vector<std::string> body);
// commands
std::string say(std::string message);
std::string tellraw(mcpp::Entity target, std::string messageJson);
} // namespace mcpp
