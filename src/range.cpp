#include "range.hpp"

std::string mcpp::packRange(mcpp::Range range)
{
    std::optional<int> min = range.min;
    std::optional<int> max = range.max;
    std::string minString = min.has_value() ? std::to_string(min.value()) : "";
    std::string maxString = max.has_value() ? std::to_string(max.value()) : "";
    return minString + ".." + maxString;
}
