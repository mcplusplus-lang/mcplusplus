#include "entity.hpp"
#include "minecraft.hpp"
#include <boost/algorithm/string/join.hpp>
#include <iostream>
#include <vector>

std::string minecraft::entity::unpackFilter(minecraft::entity::Filter filter)
{
    std::vector<std::string> result;
    std::string result_string;
    try
    {
        switch (filter.sort.value())
        {
            case NEAREST:
                result.push_back("sort=nearest");
                break;
            case FARTHEST:
                result.push_back("sort=farthest");
                break;
        };
    }
    catch (std::bad_optional_access)
    {
        std::cout << "Error: sort type unset!\n";
    }
    try
    {
        result.push_back("distance=" + minecraft::unpackRange(*filter.distance[0], *filter.distance[1]));
    }
    catch (std::bad_optional_access)
    {
        std::cout << "Error: distance range unset!\n";
    }
    return boost::algorithm::join(result, ", ");
}

std::string minecraft::entity::self()
{
    return "@s";
};

std::string minecraft::entity::self(minecraft::entity::Filter filter)
{
    return std::string("@s[") + minecraft::entity::unpackFilter(filter) + std::string("]");
};

std::string minecraft::entity::nearest()
{
    return "@n";
};

std::string minecraft::entity::nearest(minecraft::entity::Filter filter)
{
    return std::string("@n[") + minecraft::entity::unpackFilter(filter) + std::string("]");
};

std::string minecraft::entity::any()
{
    return "@e";
};

std::string minecraft::entity::any(minecraft::entity::Filter filter)
{
    return std::string("@e[") + minecraft::entity::unpackFilter(filter) + std::string("]");
};

std::string minecraft::entity::player::nearest()
{
    return "@p";
};

std::string minecraft::entity::player::nearest(minecraft::entity::Filter filter)
{
    return std::string("@p[") + minecraft::entity::unpackFilter(filter) + std::string("]");
};

std::string minecraft::entity::player::any()
{
    return "@a";
};

std::string minecraft::entity::player::any(minecraft::entity::Filter filter)
{
    return std::string("@a[") + minecraft::entity::unpackFilter(filter) + std::string("]");
};

std::string minecraft::entity::player::random()
{
    return "@r";
};

std::string minecraft::entity::player::random(minecraft::entity::Filter filter)
{
    return std::string("@r[") + minecraft::entity::unpackFilter(filter) + std::string("]");
};
