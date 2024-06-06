#pragma once
#include <optional>
#include <string>

namespace minecraft::entity
{
    // filters
    enum Sort
    {
        NEAREST,
        FARTHEST,
    };
    struct Filter
    {
        std::optional<Sort> sort;
        std::optional<int> distance[2];
    };
    std::string unpackFilter(minecraft::entity::Filter filter);
    // selectors
    std::string self();
    std::string self(minecraft::entity::Filter filter);
    std::string nearest();
    std::string nearest(minecraft::entity::Filter filter);
    std::string any();
    std::string any(minecraft::entity::Filter filter);
}; // namespace minecraft::entity

namespace minecraft::entity::player
{
    std::string nearest();
    std::string nearest(minecraft::entity::Filter filter);
    std::string any();
    std::string any(minecraft::entity::Filter filter);
    std::string random();
    std::string random(minecraft::entity::Filter filter);
}; // namespace minecraft::entity::player
