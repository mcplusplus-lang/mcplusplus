#pragma once
#include <optional>
#include <string>

namespace mcpp
{
    struct Range
    {
        std::optional<int> min;
        std::optional<int> max;
    };
    std::string packRange(mcpp::Range range);
} // namespace mcpp
