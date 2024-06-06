#pragma once
#include <optional>
#include <string>

namespace minecraft
{
    std::string unpackRange(std::optional<int> min, std::optional<int> max);
    std::string say(std::string message);
    std::string tellraw(std::string target, std::string messageJson);
} // namespace minecraft
