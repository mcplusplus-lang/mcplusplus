#include "entity.hpp"
#include "range.hpp"
#include <boost/algorithm/string/join.hpp>
#include <vector>

std::string mcpp::Entity::packFilter(std::optional<Filter> filter)
{
    if (not filter.has_value())
    {
        return "";
    }
    std::vector<std::string> result;
    std::string result_string;
    if (filter.value().sort.has_value())
    {
        switch (filter.value().sort.value())
        {
            case NEAREST:
                result.push_back("sort=nearest");
                break;
            case FURTHEST:
                result.push_back("sort=furthest");
                break;
            case ARBITRARY:
                result.push_back("sort=arbitrary");
                break;
            case RANDOM:
                result.push_back("sort=random");
                break;
        };
    }
    if (filter.value().distance.has_value())
    {
        result.push_back("distance=" + mcpp::packRange(filter.value().distance.value()));
    }
    return (std::string) "[" + boost::algorithm::join(result, ", ") + (std::string) "]";
}

std::string mcpp::Entity::packSelector(Selector selector)
{
    switch (selector)
    {
        case S:
            return "@s";
        case E:
            return "@e";
        case N:
            return "@n";
        case A:
            return "@a";
        case P:
            return "@p";
        case R:
            return "@r";
        default:
            return "";
    }
}

std::string mcpp::Entity::pack()
{
    return packSelector(selector) + packFilter(filter);
}
