#include "entity.hpp"
#include "mcpp.hpp"
#include <fstream>
#define DP_VERSION 41
#define DP_NAMESPACE "test-datapack"
#define DP_DESCRIPTION "A datapack to test mcpp's capabilities"

using namespace mcpp;

int main(int argc, char **argv)
{
    init(DP_VERSION, DP_DESCRIPTION, DP_NAMESPACE);
    std::ofstream load;
    load.open("load.mcfunction");
    load << say("hello world!");
    load << tellraw(Entity(Entity::A, {.sort = Entity::FURTHEST, .distance = Range{.min = -1, .max = 560}}), "hello world!");
    load.close();
    return 0;
}
