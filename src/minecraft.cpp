#include "minecraft.hpp"
#include <string>

std::string minecraft::unpackRange(std::optional<int> min, std::optional<int> max)
{
    std::string minString = min.has_value() ? std::to_string(min.value()) : "";
    std::string maxString = max.has_value() ? std::to_string(max.value()) : "";
    return minString + ".." + maxString;
}

std::string minecraft::say(std::string message)
{
    return "say " + message + "\n";
};

std::string minecraft::tellraw(std::string target, std::string messageJson)
{
    return "tellraw " + target + " \"" + messageJson + "\"";
}
