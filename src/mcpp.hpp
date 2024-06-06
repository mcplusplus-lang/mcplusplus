#pragma once
#include "entity.hpp"
#include <string>

namespace mcpp
{
    void init(int dp_version, std::string dp_description, std::string dp_namespace);
    std::string generate_mcmeta(int dp_version, std::string dp_description);
    std::string say(std::string message);
    std::string tellraw(mcpp::Entity target, std::string messageJson);
} // namespace mcpp
