#pragma once
#include "range.hpp"
#include <optional>
#include <string>

namespace mcpp
{
    class Entity
    {
      public:
        // selectors
        enum Selector
        {
            E,
            S,
            N,
            A,
            P,
            R,
        };
        Selector selector;
        std::string packSelector(Selector selector);

        // filters
        enum Sort
        {
            NEAREST,
            FURTHEST,
            ARBITRARY,
            RANDOM,
        };
        struct Filter
        {
            std::optional<Sort> sort;
            std::optional<mcpp::Range> distance;
        };
        std::optional<Filter> filter;
        std::string packFilter(std::optional<Filter> filter);

        // methods
        Entity(Selector selector) : selector(selector){};
        Entity(Selector selector, Filter filter) : selector(selector), filter(filter){};
        std::string pack();
    };
}; // namespace mcpp
